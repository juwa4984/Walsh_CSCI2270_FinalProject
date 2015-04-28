#include <iostream>
#include "Project1.h"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>
using namespace std;



MakeupTree::MakeupTree(){
	root = NULL;
}
MakeupTree:: ~MakeupTree(){
	
}
void MakeupTree::addProduct(string type, string brand, string title, int price, int pts){
	MakeupNode *tempMovie = new MakeupNode(type, brand, title, price,pts);

	 int counter=0;
	 //first node
	 if(root == NULL){ 
		root = tempMovie;
		root->leftChild = NULL;
		root->rightChild = NULL;
		root->parent = NULL;
	 } 
  
	else{
		MakeupNode *y=NULL;
		MakeupNode *x= root;
		MakeupNode *z = new MakeupNode(type, brand, title, price,pts);
		
		counter++;
		const char* charTitle =title.c_str();
		
		while(x!=NULL){
			y=x;
			string titleX=x->title;
			const char* charTitleX = titleX.c_str();	
			//new title is greater than root
			if(strcmp(charTitleX,charTitle)>0){
				x=x->leftChild;
			}
			else{
				x=x->rightChild;
			}
		}
		z->parent = y;
		string titleY=y->title;
		const char* charTitleY = titleY.c_str();
		if(strcmp(charTitleY,charTitle)>0){
			y->leftChild=z;
			z->leftChild=NULL;
			z->rightChild=NULL;
		}
		else{
			y->rightChild=z;
			z->leftChild=NULL;
			z->rightChild=NULL;
		}
	}	
}
	






//all of these can probably be implemented by one function, but I couldn't figure out how to do it and make it work.
//it kept incrementing the points for types other than the one found.


void MakeupTree::internalTraverseFoundation(std::string type){
	traverseFoundation(root,type);
}
//traverse the tree and if it is of type foundation, add points
void MakeupTree::traverseFoundation(MakeupNode * node, std::string type){
	if(node->leftChild!=NULL){
		traverseFoundation(node->leftChild,type);
	}
	if(node->type=="Foundation"){
		node->points=1;
	}
	
	if(node->rightChild!=NULL){
		traverseFoundation(node->rightChild,type);
	}
}
//same as above but for primer
void MakeupTree::internalTraversePrimer(std::string type){
	traversePrimer(root,type);
}
void MakeupTree::traversePrimer(MakeupNode * node, std::string type){
	if(node->leftChild!=NULL){
		traversePrimer(node->leftChild,type);
	}
	if(node->type=="Primer"){
		node->points=1;
	}
	
	if(node->rightChild!=NULL){
		traversePrimer(node->rightChild,type);
	}
}

void MakeupTree::internalTraverseMascara(std::string type){
	traverseMascara(root,type);
}
void MakeupTree::traverseMascara(MakeupNode * node, std::string type){
	if(node->leftChild!=NULL){
		traverseMascara(node->leftChild,type);
	}
	if(node->type=="Mascara"){
		node->points=1;
	}
	
	if(node->rightChild!=NULL){
		traverseMascara(node->rightChild,type);
	}
}

void MakeupTree::internalTraverseEyeshadow(std::string type){
	traverseEyeshadow(root,type);
}
void MakeupTree::traverseEyeshadow(MakeupNode * node, std::string type){
	if(node->leftChild!=NULL){
		traverseEyeshadow(node->leftChild,type);
	}
	if(node->type=="Eyeshadow"){
		node->points=1;
	}
	
	if(node->rightChild!=NULL){
		traverseEyeshadow(node->rightChild,type);
	}
}

void MakeupTree::internalTraverseFacewash(std::string type){
	traverseFacewash(root,type);
}
void MakeupTree::traverseFacewash(MakeupNode * node, std::string type){
	if(node->leftChild!=NULL){
		traverseFacewash(node->leftChild,type);
	}
	if(node->type=="Face Wash"){
		node->points=1;
	}
	
	if(node->rightChild!=NULL){
		traverseFacewash(node->rightChild,type);
	}
}

void MakeupTree::internalTraverseMoisturizer(std::string type){
	traverseMoisturizer(root,type);
}
void MakeupTree::traverseMoisturizer(MakeupNode * node, std::string type){
	if(node->leftChild!=NULL){
		traverseMoisturizer(node->leftChild,type);
	}
	if(node->type=="Moisturizer"){
		node->points=1;
	}
	
	if(node->rightChild!=NULL){
		traverseMoisturizer(node->rightChild,type);
	}
}

//traverse tree and print inventory if points are = 1
void MakeupTree::printInventoryAfter(MakeupNode * node){

	if(node->leftChild!=NULL){
		printInventoryAfter(node->leftChild);
	}
	if(node->points != 0){
		cout<<node->brand<<": " <<node->title<<" "<<"  $"<<node->price<<endl;
	}
	if(node->rightChild!=NULL){
		printInventoryAfter(node->rightChild);
	}
}

void MakeupTree::printInventoryAfter(){
	printInventoryAfter(root);
}


MakeupNode* MakeupTree::searchMakeupTree(MakeupNode * node, std::string ttl){

	if(node == NULL){
		cout<<"Not found."<<endl;
		return node;
	 }
	 else if(node->title== ttl){
		 return node;
	 }
	 else{
		 
		if(node->title > ttl){
			return searchMakeupTree(node->leftChild, ttl);
			
		}
		 
		else{
			return searchMakeupTree(node->rightChild,ttl);
		}
	 }
	 cout<<"Not found"<<endl;
 }
 

 
void MakeupTree::findProduct(std::string title){
MakeupNode *foundProduct = searchMakeupTree(root,title);


		if(foundProduct!=NULL){
				cout<<"**Product Information**"<<endl;
	cout<<"Here is your item info:"<<endl;
	cout<<"==========="<<endl;
	cout<<"Type of Item:"<<foundProduct->type<<endl;
	cout<<"Brand:"<<foundProduct->brand<<endl;
	cout<<"Product Name:"<<foundProduct->title<<endl;
	cout<<"Price:"<<foundProduct->price<<endl;
		}
}

void MakeupTree::findForCart(std::string title,int pos){
	//add product price to array
	MakeupNode *foundProduct = searchMakeupTree(root,title);
	shoppingCart[pos-1]=foundProduct->price;
	
}

void MakeupTree::displayTotal(){
	//print array of chosen products
	int sum=0;
		for(int i=0; i<5; i++){
			cout<<shoppingCart[i]<<endl;
			sum+=shoppingCart[i];
		}
		cout<<"Your total is $"<<sum<<endl;
}


