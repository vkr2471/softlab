// Name: Voddula Karthik Reddy  *
//                              *
// Roll No: 21CS30058           *
//                              *
// Software Engineering lab     *
//             Assignment -1    *
// Language : C++               *
// ******************************



//Librarys used : iostream ,math.h , string , vector,algorithm
//
//Resoureses used :
//                  Newtons Meathod : https://en.wikipedia.org/wiki/Newton%27s_method
//                  ------------------------------------------------------------------
//Not used multiple files as asked

#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

const long double EPSILON =powl(10,-9); //defining default value of epsilon as 10^-9

// Strucutre definnig a Polynomial :Polyn
typedef struct node
{
    long double coeff; //using long double for co-efficent 
    unsigned long long int degree; // using unsigned long long int for degree becuase degree is a non negatvive integer 
    struct node* next; // next contains pointer to next degree if it exists 
    

}Polyn;

// Structre defining properties of a polynomial : name of the polynomial,the polynomial and a boolian ini to check if polynomial is initialized
typedef struct 
{
    string name;
    Polyn p;
    bool ini;
}polys;

vector<polys>db; // defining a global vector to store polynomials and their properites 
//Used Vector over linked list to store differnet polynomials becuase there is not much diffrence between them as names are used to represent diffrent polynimals and vectors are easy to implement 

polys x; // defining a global polynomial so to store intemediate results during caluculations like zero of Polynomial
inline const bool operator<(const polys&a,const polys&b)
{
  return(a.name<b.name);
}
//Function to create nodes of a Polynomial
Polyn* create_node(unsigned long long int d,long double c)
{
    Polyn* temp=(Polyn*)malloc(sizeof(Polyn)); // dynamically allocating memory
    temp->coeff=c; // assigning the coeffient
    temp->degree=d; // assinging the degree
    temp->next=NULL; // setting the next pointer to null;
    return temp; 
}

//Function to find if a Polynomial exists 
int find(string s)
{
    for(int i=0 ;i<db.size();i++)
    {
        if(s== db[i].name)
        {
            return i;// an polynomial with given name found
        }
    }
    return -1;// no match found
}
inline auto find1(string s)
{
  auto t=lower_bound(db.begin(),db.end(),s); 
  return t;
}

//function to print polynomials
void print_poly(polys& a)
{
    
    cout<<"name: "<<a.name<<"\n";// printing name 
    if(!(a.ini))cout<<"not initilized\n";//checking if polynomial is initialized
    else
    {
					
        Polyn* ptr=&(a.p);
        while(ptr!=NULL)
        {
					if((ptr->coeff>0))// printing terms with positive coeffient
						{
							cout<<"+"<<ptr->coeff<<"*x^"<<ptr->degree<<" ";
								
	      		}
						else// printing terms with negative coefficient
           {
             cout<<ptr->coeff<<"*x^"<<ptr->degree<<" ";
           }
				
            ptr=ptr->next;
        }
    }
    cout<<"\n \n";
    
}

//Function to Instantiate new polynimial
void create_poly()
{

    polys x;
    cout<<"enter the name of the polynomial: ";
    cin>>x.name;
    int t =find(x.name); //Checking if name exists already
    if(t!=-1)
    {
        cout<<"A Polynimial already exists with that name\n ";
        print_poly(db[t]);
        return ;
    }
    (x).ini=0;// setting initilized variable to 0
  // auto p= upper_bound(db.begin(),db.end(),x.name);
  // auto p= find1(x.name);
    //if(p==db.end()) 
    db.push_back(x);
    //else if((db.begin()+p).name==x.name)
  
    
    

}

//Function to add a term to the polynomial and also mainting the linked list such that 
void addremoveterm(polys &a,unsigned long long int d,long double c)
{
    if(!(a.ini) )//checking if polynomial is initilized if not then making is initialzed to true
    {
        (a.p).coeff =c;
        (a.p).degree=d;
        a.ini =1;
        (a.p).next=NULL;
        return;
    }
    else
    {
        Polyn *ptr=&(a.p);
        while((ptr->next!=NULL)&&((ptr->next)->degree<d))ptr=ptr->next;// getting the degree just less than the degree to be inseted (only if the pointer moves)
        if(ptr==&(a.p))//This means the pointer has not moved it has three cases
        {
            if(ptr->degree==d)//case when the start degree is same as degree to be inserted
            {
                ptr->coeff=(ptr->coeff) +c;
                return;
            }
            else 
            {
                if(ptr->degree>d)//case when start degree is greeater than degree to be inserted here we make new node adjecent to current head and then transfer the coeffient and degree to it
                {
                  //  cout<<"hello\n";
                    Polyn* temp;
                    temp =ptr->next;
                    ptr->next=create_node(ptr->degree,ptr->coeff);
                    ptr->next->next=temp;
                    ptr->coeff=c;
                    ptr->degree=d;
                    return;
                }
                else// case when start degree is smaller than degree to be inserted ,here we create a new node adjecent to cureent and head and assign the degree and coeffient to be inserted also assiginig the cureent nesxxt as next to inserted node
                {
                    Polyn* temp =ptr->next;
                    ptr->next=create_node(d,c);
                    ptr->next->next =temp;
                    return;
                }
            }
        }
        else if(ptr->next==NULL)//if the element to be inserted is the last element then we just create it
        {
        
            ptr->next=create_node(d,c);
            print_poly(db[0]);
        }
        else//in this case the pointer stops just before the degree to be inserted
        {
             if((ptr->next)->degree==d)//if we alredy have the degree so we just add the coeffient
            {
               ( ptr->next)->coeff=((ptr->next)->coeff)+c;
                return;
            }

      //case when the degree does not exist here we just insert the node at ptr->next also assign the next element of newly inserted node as previous next      
            Polyn* temp=ptr->next;
            ptr->next=create_node(d,c);
            ptr->next->next = temp;
        }
    }
}

//Function to delete a term from the polynomial
void addremoveterm(polys& a ,unsigned long long int d)
{
    if(!(a.ini))//checking if the polynomial is initialzed
    {
        cout<<"The polynomial is not initialized\n";
        return ;
    }
    Polyn* ptr=&(a.p);
    if(ptr->degree==d)//if the element to be deleted is the head
    {
        if(ptr->next!=NULL)// if next element exists then we assign head the contents of next element and then we delete the next elemnent also assigning next element of head as next to next element
        {
            Polyn* temp=ptr->next;
            ptr->degree=ptr->next->degree;
            ptr->coeff=ptr->next->coeff;
            ptr->next=ptr->next->next;
            temp->next =NULL;
            free(temp);
            
            
        }
        else// if there does not exit element then we simply make is initialzed to false 
        {
            a.ini=0;
        }
    }
    while((ptr->next!=NULL)&&(ptr->next)->degree!=d)ptr=ptr->next;//moving untill wwe find pointer whose next elements degree is d(if it exists)
    if(ptr->next==NULL)//case when degree does not exist
    {
        cout<<"The entered degree does not exist\n";
        return ;
    }
    else// if degree exists then we make next to next element of pointer as the next element of the pointer and then we delete the previous next element of pointer 
    {
        Polyn* temp=ptr->next;
        ptr->next=ptr->next->next;
        temp->next=NULL; 
        free(temp);
    }
}


//Function to delete terms whose absolute value of coeeficient is less than epsilon
void addremoveterm(polys& a, int b,  int c,long double epsilon =EPSILON)
{
    if(!(a.ini))//checking if the function is initialzed
    {
        cout<<"The polynomial is not initialized\n";
        return ;
    }
    Polyn* ptr=&(a.p);
    while(abs(ptr->coeff)<epsilon)//case where we have to delete the head we delete recursvily until when head no longer needs to be deleted
    {
        if(ptr->next==NULL)//need to delte only remaining element ie head so we just set is ini to false
        {
            a.ini=0;
            return;
        }
        else//recursvily deleting untill head no longer needs to be deleted 
        {
            Polyn* temp=ptr->next;
            ptr->degree=ptr->next->degree;
            ptr->coeff=ptr->next->coeff;
            ptr->next=ptr->next->next;
            free(temp);

        }
    }
    while(ptr->next!=NULL)// case where we need to delete other elements other than head 
    {
        if(abs((ptr->next)->coeff)<epsilon)//checking if the term next to ptr  needs to be deleted and recursivly deleting ie here we delete in clusters
        {
            Polyn* temp= ptr->next;
            ptr->next=ptr->next->next;
            free(temp);//deleting the term 
        }
        if(abs((ptr->next)->coeff)>=epsilon)ptr=ptr->next;//finding next cluster
    }

}
\

//function to evaluate a given polynomial at x
long double evaluate(polys& a,long double x)
{
    if(!(a.ini))//checking if polynomial is initialezed
    {
        cout<<"Polynomial not initialized\n";
        return -1;
    }
    Polyn* ptr=&(a.p);//initialixzing ptr to point to first element 
    unsigned long long int d=0;//string the highest degree of x evalutaed previsouly
    long double running=1;// stroing the highest power of x evaluateed so as to improve efficiency
    long double ans=0;//initilzing initial answer to 0
    while(ptr!=NULL)//interating over the polynomial
    {
        running*=powf(x,(ptr->degree)-d);//updating running power
        d=ptr->degree;//updating the highest degree
        ans+=(ptr->coeff)*running;//incresing the answer
        ptr=ptr->next;
    }
    //priting the answer 
    cout<<"The value of given polynomial\n";
    print_poly(a);
    cout<<"at x= "<<x<<"is: "<<ans<<"\n";
    return ans ;
}


//function to add to polynomials
//
//This function uses smiliar logic as that of merge function in merge sort this meathod is commonly reffred as two pointer meadthod
void add(polys& p1,polys&p2)
{
    if(!p1.ini)//checking if first polynomail is initialzed
    {
        cout<<"first polynomial not initialized\n";
        return;
    }
    if(!p2.ini)//checking if second polynomail is initilized
    {
        cout<<"second polynomial not initialezed\n";
        return ;
    }
    Polyn* ptr1=&(p1.p);//storing head of first polynomial
    Polyn* ptr2=&(p2.p);//string head of second polynomaial
    polys p;//creating a new polynomial to store resultant
    cout<<"enter a name for resultant polynomial\n";//asking name for resultant polynomial
     cin>>p.name;
    int t =find(p.name);//checking if a polynomial with that name exists
    if(t!=-1)
    {
        cout<<"A Polynimial already exists with that name\n ";
        print_poly(db[t]);
        return ;
    }
    (p).ini=0;
    while(ptr1!=NULL&&(ptr2!=NULL))/*two pointer meathod to interate on two polynmials here we are using the fact that the two polynomials are stored
  in sorted fasion*/
    {
        if(ptr1->degree==ptr2->degree)//case where both degrees are same here we add the coffients and add the term with common degree into  resultant polynomial
        {
            addremoveterm(p,ptr1->degree,(ptr1->coeff)+(ptr2->coeff));
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        else if(ptr1->degree<ptr2->degree)//case where the pointer to first polynomial is having lesser degree than second polynomail
        {
            addremoveterm(p,ptr1->degree,ptr1->coeff);//here we add the term with degree and coeffientas that of first polynomial
            ptr1=ptr1->next;//incrimenting the pointer1
        }
        else // case where hte pointr to second polynomail is lesser than the first polynomial
        {
            addremoveterm(p,ptr2->degree,ptr2->coeff);// here we add the term with degree and coeffients that of second polynomial 
            ptr2=ptr2->next;//incrementing second polynomial
        }
       
    }
     while(ptr1!=NULL)//adding the terms if left over from first polynomial
        {
            addremoveterm(p,ptr1->degree,ptr1->coeff);
            ptr1=ptr1->next;

        }
         while(ptr2!=NULL)//adding the terms if left over from second polynomial
        {
            addremoveterm(p,ptr2->degree,ptr2->coeff);
            ptr2=ptr2->next;

        }
    db.push_back(p);//storing the resultant polynomial into database
    cout<<"The resultant polynomial after additon is : \n";
    print_poly(db[db.size()-1]);
    return ;
}

//function to find derivative of a polynomial
polys& derivative(polys&a)
{
    if(!a.ini)//checking if polynomial is initialized
    {
        cout<<"The polynomial is not initilized\n";
        return a;
    }
    Polyn* ptr=&(a.p);//storing head 
 
    
    while(ptr!=NULL)
    {
        if(ptr->degree!=0)
        {
           addremoveterm(x,(ptr->degree)-1,(ptr->degree)*(ptr->coeff));//derivative of a*x^n is a*n*x^(n-1)
        }
        ptr=ptr->next;
    }
    cout<<"The derviative of given polynimial is :\n";
    print_poly(x);
    return x;
}

//funtion to find zero of a polynomial using newtons meathod : we succesivly iterate on x =x-f(x)/f'(x) untill deired accuracy is acheived
//
//reusources used : https://en.wikipedia.org/wiki/Newton%27s_method
void zero_newton(polys& a,long double x0,long double epsilon=EPSILON)
{
    if(!a.ini)//checking if polynomial is initialized
    {
        cout<<"given polynomial not initialized\n";
        return ;
    }
    long double x1=x0;
    long double x3;
    derivative(a);//finding the derivative and stroing it in global temporary variable x
    long double x2= evaluate(a,x0);//evaluating f(x) at initial point
    while(abs(x2)>epsilon)//iterrating untill desired accuracy is acheived
    {
        x3=evaluate(x,x1);
        if(x3==0)
        {
            cout<<"Cannot evalute zero of given polynomial under given conditios using newtons meathod (f'(x) becomes zero at intermdiate step)\n";
            return ;

        }
        x1=x1-(x2/x3);//x=x-f(x)/f'(x)
        x2=evaluate(a,x1);

    }
    cout<<"A zero of entered polynomial is "<<x1;
}

//funcion to delete a whole polynomial
void delete_poly()
{
		
    string name;
    cout<<"enter the name of polynomial\n";
    cin>>name;
    int t=find(name);//finding polynomial to be deleted
    //cout<<t;
    if(t==-1)
    {
        cout<<"no polynomial found\n";
        return;
    }
    Polyn* ptr;
    ptr=&(db[t].p);
    ptr=ptr->next;
    if(!(db[t].ini))//if polynmial is not initialized we simply delete it
    {
        db.erase(db.begin()+t);
    }
    Polyn* temp;
    while(ptr!=NULL)//recursivly deleting each node of polynomial(freeing the dynamically allocated memory)
    {
        temp=ptr->next;
        ptr->next=NULL;
        free(ptr);
        ptr=temp;  
    }
    db.erase(db.begin()+t);//erasing the polynomial after all the nodes that were dynamically allocated are freed
    return;
}


int main()
{
		
		int option,t,i,j;
		
		string name,name1;

	  unsigned long long int d;

		long double c,epsilon,y;

    x.name="result";
    x.ini=0;
    //user console
	  cout<<"Maximize the Terminal to have a smooth experiance\n";

		cout<<"Welcome to POLYVERSE-The world of Polynomials! Knowing that you are wise  ZEUS appointed you to populate POLYVERSE\n";

		cout<<"Ready for the Task? Press any number to continue\n";

		cin>>t;

		cout<<"Knowing that it is a Herculian task , ZEUS assigned me (HERCULES) to define laws of POLYVERSE\n ";

		cout<<"You are provided wtih the following laws\n";
		while(1)
		{
			cout<<" 1) Instantiate a new polynomial (give brith )\n ";

			cout<<" 2) Add a term  to the polynomial (add a  cell)\n ";

			cout<<" 3) Remove a term  of the polynomial(remove a aged cell)\n";

			cout<<" 4) Remove all terms with coeffient less than epsilon (remove foreign cells that have entered)\n";

			cout<<" 5) Evaluate a Polynomial at x(caluculate amount of matter in the polynomial )\n";

			cout<<" 6) Add two polynomials to create new polynomal (marry two polynimials)\n";

			cout<<" 7) Differntiate a Polynomial (find how fast the matter is changing in the polynomial)\n";

			cout<<" 8) Caluculate a zero (root) of the polynomial using newtons meathd (find the time at which the polynomial is a PHEONIX)\n";

			cout<<" 9)  Delete a polynomial (Give death to the polynomial for the crimes it commited  )\n";

			cout<<" 10) Print all the polynomials present in PLOYVERSE\n";

			cout<<" 11) Exit the program\n";

			cout<<"Enter a option\n";

			cin>> option;

			switch(option)
				{
					case 1:

					create_poly();
					break;
					
					case 2:

					cout<<"enter the name of polynomial\n";
					cin>>name;
					i=find(name);
					if(i==-1)
						{
							cout<<"No such Polynomial\n";
							break;
						}
					cout<<"Enter degree of the term to be added\n";
					cin>>d;
					cout<<"Enter coeffient of the term to be added\n";
					cin>>c;
					addremoveterm(db[0],d,c);
					break;

					case 3:

					cout<<"Enter the name of the Polynomial\n";
					cin>>name;
					i=find(name);
					if(i==-1)
						{
							cout<<"No such Polynomial\n";
							break;
					}
					cout<<"Enter the degree to be deleted\n";
					cin>>d;
					addremoveterm(db[i],d);
					break;

					case 4:

					cout<<"Enter the name of the Polynomial\n";
					cin>>name;
					i=find(name);
					if(i==-1)
						{
							cout<<"No such polynomial\n";
							break;
					}
					cout<<" Enter the value of epsilon , enter -1 to use default epsilon\n";
					cin>>epsilon;
					if(epsilon==-1)
						{
							addremoveterm(db[i],0,0);
					}
						else if(epsilon<-1)
						{
							cout<<"no term to delete as epsilon is negative\n";
							break;
						}
					else{
							addremoveterm(db[i],0,0,epsilon);
					}
					break;

					case 5:

          cout<<"Enter the name of the polynomial\n";
					cin>>name;
					i=find(name);
					if(i==-1)
						{
							cout<<"No such Polynomial\n";
							break;
					}
					cout<<"Enter x\n";
					cin>>y;
					evaluate(db[i],y);
					break;

					case 6:

					cout<<"Enter the name of first polynomial\n";
					cin>>name;
					i=find(name);
					if(i==-1)
						{
							cout<<"no such polynomial found\n";
							break;
					}
					cout<<"Enter the name of second Polynomial\n";
					cin>>name1;
					j=find(name);
					if(j==-1)
						{
							cout<<"no such plynomial\n";
							break;
					}
					add(db[i],db[j]);
					break;

					case 7:

					cout<<"Enter the name of the polynomial\n";
					cin>>name;
					i=find(name);
					if(i==-1)

						{
							cout<<"no such polynomial\n";
							break;
					}
					derivative(db[i]);
					break;

					case 8:

					cout<<"enter the name of the polynomial\n";
					cin>>name;
					i=find(name);
					if(i==-1)
						{
							cout<<"no such Polynomial \n";
							break;
					}
					cout<<"enter initial value of polynomial \n";
					cin>>y;
					cout<<"enter the value of epsilon, enter -1 to use default value\n";
					cin>>epsilon;
					if(epsilon==-1)
						{
							zero_newton(db[i],y);
							break;
						}
					else if(epsilon<-1)
						{
							cout<<"negative value entered\n";
								break;
					}
					else{
							zero_newton(db[i],y,epsilon);
					}
					break;

					case 9:

					delete_poly();
					break;

					case 10:
					for(auto k:db)
						{
							print_poly(k);
					}
					cout<<"\n";
					break;

					case 11:

					cout<<"ZEUS is pleased with your service! Have a good time\n";
					exit(0);

					default:

					 cout<<"Invalid choice\n";


			  }

			x.ini=0;

			
	  }
	

		return 0;
}
