#ifndef PROJECT1_H
#define PROJECT1_H


struct MakeupNode{
    std::string type;
    std::string brand;
    std::string title;
    int price;
    int points;
    int shoppingCart[5];
    MakeupNode *parent;
    MakeupNode *leftChild;
    MakeupNode *rightChild;


    MakeupNode(){};

   MakeupNode(std::string ty, std::string br, std::string nm,  int pr, int pts)
    {
        type=ty;
        brand=br;
        title=nm;
        price=pr;
        points=pts;
    }

};

class MakeupTree
{
    public:
        MakeupTree();
        virtual ~MakeupTree();
        int shoppingCart[5];
        void printInventory();
        void printInventoryAfter();
        void addProduct(std::string ty, std::string br, std::string nm, int pr, int pts);
        void findProduct(std::string title);
        void getItem(std::string title);
        void deleteItem(std::string title);
        void internalTraverseFoundation(std::string type);
        void internalTraverseMascara(std::string type);
        void internalTraverseEyeshadow(std::string type);
        void internalTraverseFacewash(std::string type);
        void internalTraverseMoisturizer(std::string type);
        void internalTraversePrimer(std::string type);
		void displayTotal();
        void findForCart(std::string title,int pos);
        int countNodes();
        MakeupNode* min();

    protected:
    private:
        void printInventory(MakeupNode * node);
        void printInventoryAfter(MakeupNode * node);
        //void deleteRemainder(MakeupNode * node);
        int countNodes(MakeupNode *node);
        MakeupNode* searchMakeupTree(MakeupNode* node, std::string ttl);
        void traverseFoundation(MakeupNode * node, std::string type);
        void traversePrimer(MakeupNode * node, std::string type);
        void traverseMoisturizer(MakeupNode * node, std::string type);
        void traverseEyeshadow(MakeupNode * node, std::string type);
        void traverseFacewash(MakeupNode * node, std::string type);
        void traverseMascara(MakeupNode * node, std::string type);
        
        
        MakeupNode *root;
        MakeupNode* min(MakeupNode *node);
        void swap_node(MakeupNode* x, MakeupNode*y);
        int opCount;
};

#endif // PROJECT1_H
