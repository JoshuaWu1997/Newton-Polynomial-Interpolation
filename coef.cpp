#include<iostream>
#include<malloc.h>
#include "coef.h"
using namespace std;

coef::coef(){
	PointNum=0;
	Node=create();
}
tree* coef::AddNode(int i,tree* HNext){
	tree* head;
	head=create();
	head->next=HNext;
	if(i==0){
		tree* point;
		point=create();
		point->y=y[PointNum];
		head->right=point;
		head->y=(y[PointNum-1]-y[PointNum])/(x[PointNum-1]-x[PointNum]);
		return head;
	}
	else{
		tree* point;
		head->right=point=AddNode(i-1,HNext->right);
		head->y=(HNext->y-point->y)/(x[PointNum-i-1]-x[PointNum]);
		return head;
	}
}
void coef::Add(double xx,double yy){
	PointNum++;
	x[PointNum]=xx;
	y[PointNum]=yy;
	Node=AddNode(PointNum-1,Node);
}
void coef::input(){
	destruct(Node);
	Node=create();
	PointNum=0;
	build();
	cout<<"Input successfully!\n";
}
tree* coef::create(){
	tree* p;
	p=(tree*)malloc(sizeof(tree));
	p->next=NULL;
	p->right=NULL;
	p->y=0;
	return p;
}
void coef::destruct(tree* p){
	if (p->right!=NULL) destruct(p->right);
	if (p->next!=NULL) destruct(p->next);
	free(p);
}
double coef::Getcoef(int n,int pos){
	int i; double temp;
	temp=0;
	if (n==0) return 1;
	else for(i=pos;i<=PointNum-n;i++)  temp+=Getcoef(n-1,i+1)*(-x[i]);
	return temp;
}
void coef::build(){
	int n;
	int i,j;
	cin>>n;
	cin>>x[0]>>y[0];
	Node->y=y[0];
	c[0]=0; c[0]+=y[0];
	for(i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		Add(x[i],y[i]);
		c[i]=Node->y;
		for(j=0;j<=i-1;j++){
			c[j]+=Node->y*Getcoef(i-j,0);
		}
	}
	if(c[0]!=0) cout<<c[0]<<'+';
	for(i=1;i<=n;i++){
		if(c[i]>0){
			if(c[i]!=1) cout<<c[i]<<"x^"<<i;
			else cout<<"x^"<<i;
			if(i!=n) cout<<"+";
		}
		if(c[i]<0){
			if(c[i]!=-1) cout<<c[i]<<"x^"<<i;
			else cout<<"x^"<<i;
		}
	}
	cout<<endl;
}
double coef::GetValue(double p,int level,tree* head){
	double value; int i;
	value=head->y;
	if (level==0) return value;
	else{
		for(i=0;i<=level-1;i++) value*=(p-x[i]);
		return value+GetValue(p,level-1,head->next);
	}
}
double coef::OutputValue(double p){
	return GetValue(p,PointNum,Node);
}
coef::~coef(){
	destruct(Node);
}





