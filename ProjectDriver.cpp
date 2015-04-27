#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include "Project1.h"

using namespace std;

int main(){
	
	MakeupTree *myTree= new MakeupTree();
	int userChoice;
	bool inGame=true;
	
	ifstream fn;
	fn.open("ProjectItems.txt");
	string line;
	while (getline(fn,line)){
		stringstream iss(line);
		string category;
		getline(iss,category,',');
		string brand;
		getline(iss,brand,',');
		string product_name;
		getline(iss,product_name,',');
		string price;
		getline(iss,price,',');
		int item_price = stoi(price);
		string points;
		getline(iss,points,',');
		int number_points=stoi(points);

		myTree->addProduct(category,brand,product_name,item_price,number_points);


	}
	cout<<endl;
			cout<<"~ Welcome to my beauty shop ~"<<endl;
			cout<<"What are your three favorite products to use? Choose from the following. Type in the product name exactly as shown, hitting enter after each one."<< endl;
			cout<<"* Primer *"<<endl;
			cout<<"* Foundation *"<<endl;
			cout<<"* Mascara *"<<endl;
			cout<<"* Eyeshadow *"<<endl;
			cout<<"* Face Wash *"<<endl;
			cout<<"* Moisturizer *"<<endl;
			
			string input1;
			cout<<"Product 1: "<<endl;
			cin>>ws;
			getline(cin,input1);
			
			
			string input2;
			cout<<"Product 2: "<<endl;
			cin>>ws;
			getline(cin,input2);
			
			
			string input3;
			cout<<"Product 3: "<<endl;
			cin>>ws;
			getline(cin,input3);
			
			if(input1=="Primer"||input2=="Primer"||input3=="Primer"){
				myTree->internalTraversePrimer("Primer");
			}
			if(input1=="Foundation"||input2=="Foundation"||input3=="Foundation"){
				myTree->internalTraverseFoundation("Foundation");
			}
			if(input1=="Mascara"||input2=="Mascara"||input3=="Mascara"){
				myTree->internalTraverseMascara("Mascara");
			}
			if(input1=="Face Wash"||input2=="Face Wash"||input3=="Face Wash"){
				myTree->internalTraverseFacewash("Face Wash");
			}
			if(input1=="Eyeshadow"||input2=="Eyeshadow"||input3=="Eyeshadow"){
				myTree->internalTraverseEyeshadow("Eyeshadow");
			}
			if(input1=="Moisturizer"||input2=="Moisturizer"||input3=="Moisturizer"){
				myTree->internalTraverseMoisturizer("Moisturizer");
			}
			cout<<"The following products may fit more of what you like. "<<endl;
			myTree->printInventoryAfter();
			
			
			cout<<"If you would like information on any of the following products, please type 'More Info' at any time. If not, please type 'Continue'."<<endl;
			string moreInfo;
			cin>>ws;
			getline(cin,moreInfo);

				if(moreInfo == "More Info"){
					cout<<"Type the name of the product you would like to see.  (Name is part after colon)." <<endl;
				string productToFind;
				cin>>ws;
				getline(cin,productToFind);
				myTree->findProduct(productToFind);
				cout<<endl;
			}
		
			cout<<"Type in the names of your favorite 5 products: "<<endl;
			string prod1;
			cout<<"Product 1: "<<endl;
			cin>>ws;
			getline(cin,prod1);
			myTree->findForCart(prod1,1);
			
			
			string prod2;
			cout<<"Product 2: "<<endl;
			cin>>ws;
			getline(cin,prod2);
			myTree->findForCart(prod2,2);
			
			
			string prod3;
			cout<<"Product 3: "<<endl;
			cin>>ws;
			getline(cin,prod3);
			myTree->findForCart(prod3,3);
			
			string prod4;
			cout<<"Product 4: "<<endl;
			cin>>ws;
			getline(cin,prod4);
			myTree->findForCart(prod4,4);
			
			
			string prod5;
			cout<<"Product 5: "<<endl;
			cin>>ws;
			getline(cin,prod5);
			myTree->findForCart(prod5,5);
			
		myTree->displayTotal();
			
			
		
		
			
		
			
		
			
			
		
};
