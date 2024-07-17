#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

struct BSTNode
{
    BSTNode* up, * left, * right;
    int key;
};

string cr, cl, cp;

void printBT(string sp, string sn, BSTNode* v)
{
    string s;

    if (v)
    {
        s = sp;
        if (sn == cr) s[s.length() - 2] = ' ';
        printBT(s + cp, cr, v->right);

        s = s.substr(0, sp.length() - 2);
        cout << s << sn << v->key << endl;

        s = sp;
        if (sn == cl) s[s.length() - 2] = ' ';
        printBT(s + cp, cl, v->left);
    }
}

void DFSRelease(BSTNode* v)
{
    if (v)
    {
        DFSRelease(v->left);  
        DFSRelease(v->right); 
        delete v;                
    }
}

void insertBST(BSTNode*& root, int k)
{
    BSTNode* w, * p;

    w = new BSTNode;           

    w->left = w->right = NULL;
    w->key = k;               

    p = root;            

    if (!p)                  
        root = w;               
    else
        while (true)            
            if (k < p->key)       
            {                      
                if (!p->left)       
                {
                    p->left = w;       
                    break;             
                }
                else p = p->left;
            }
            else
            {
                if (!p->right)       
                {
                    p->right = w;      
                    break;             
                }
                else p = p->right;
            }

    w->up = p;                

}

int main()
{
    BSTNode* root = NULL;
    int i, k;

    cr = cl = cp = "  ";
    cr[0] = 218; cr[1] = 196;
    cl[0] = 192; cl[1] = 196;
    cp[0] = 179;

    srand(time(NULL));  

    for (i = 0; i < 20; i++) 
    {
        k = 1 + rand() % 9;    
        cout << k << " ";       
        insertBST(root, k);  
    }

    cout << endl << endl;

    printBT("", "", root); 
    DFSRelease(root);      

    return 0;
}