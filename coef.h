#define MAX 100

typedef struct tree{
		double y;
		struct tree* next;
		struct tree* right;
	}tree;

class coef{
public:
	coef();
	void input();
	double OutputValue(double p);
	void Add(double xx,double yy);
	~coef();
private:
	tree* Node;
	int PointNum;
	double c[MAX];
	double x[MAX];
	double y[MAX];
	tree* create();
	void destruct(tree* p);
	double Getcoef(int n,int pos);
	void build();
	tree* AddNode(int i,tree* HNext);
	double GetValue(double p,int level,tree* head);
};
