//classes///////////////////////////////////////////////////////////////////////////////////////////
/*
#include <iostream>
#include <cstring>
using namespace std;
class car{
private:
    char name[14];
    char color[23];
    int maxspeed;
    int model;
public:
    void setname(char n[]){
    strcpy(name,n);
    }
    void setmaxspeed(int n){
    maxspeed=n;
    }
    char* getname(){
    return name;
    }
    int getmaxspeed(){
    return maxspeed;
    }
    void print(){
    cout<<name<<endl;
    cout<<getmaxspeed();
    }
};
int main()
{
    car x;
    x.setname("kia");
    x.setmaxspeed(1222);
    x.print();
    //cout<<getname();
}
*/




//constructors//////////////////////////////////////////////////////////////////////////////////
/*
//must be studied again
#include <iostream>
#include <cstring>
using namespace std;
//constructors must different from each other by number of parameters of data type of parameters
class triangel{
int base;
int height;
public:
    triangel()
    {
        cout<<"empty constructor"<<endl;
        base=2;
        height=4;
    }
    triangel(int b,int h)
    {
        cout<<"parameterized constructor"<<endl;
    base=b;
    height=h;
    }
    void setbaseandheight(int b, int h){
    base=b;
    height=h;
    }
    float area(){
    return 0.5*base*height;
    }
    void print(){
    cout<<"base ="<<base<<endl;
    cout<<"height ="<<height<<endl;
    cout<<"area ="<<area()<<endl;
    }

};
class coppy{
//to reduce number of attributes into an object so we do not repeat all of them in member function parameters
int a1,a2,a3,a4,a5,a6,a7,a8;
public:
    coppy(int b1, int b2, int b3, int b4, int b5, int b6, int b7, int b8) {

        //this constructor is important you can not make copy constructor without parameterized constructor or an already existing object
    a1 = b1;
    a2 = b2;
    a3 = b3;
    a4 = b4;
    a5 = b5;
    a6 = b6;
    a7 = b7;
    a8 = b8;
}

    coppy(const coppy&a)//takes an object a not usual variable
    {
        cout<<"copy constructor"<<endl;
       a1=a.a1;
       a2=a.a2;
       a3=a.a3;
       a4=a.a4;
       a5=a.a5;
       a6=a.a6;
       a7=a.a7;
       a8=a.a8;
    }
    void print(){
    cout<<a1<<a2<<a3<<a4<<a5<<a6<<a7<<a8;
    }
};
int main(){
//every object only calls one constructor
triangel ob1;
ob1.print();
triangel ob2(6,7);
ob2.print();
//ob1.setbaseandheight(10,5); for assigning other values than what is in constructors
    // Create coppy object using parameterized constructor
    coppy cop1(1, 2, 3, 4, 5, 6, 7, 8);
    cop1.print();

    // Create another coppy object using the copy constructor
    coppy cop2 = cop1;
    cop2.print();

    // Create another coppy object using the copy constructor
    coppy copy(cop1);
    copy.print();
}
*/




//destructors/////////////////////////////////////////////////////////////////////////////////////
/*
//only one type an does not take any parameters
//destroys the objects from down to top"the last one is the first to be destroyed and excut what is in its destructor
//if we define a parameterized constructor and we want to initialize an object without passing any parameters we should define a default empty constructor regardless of the parameterized one or remove the parameterized one
#include <iostream>
#include <cstring>
using namespace std;
class rectangle{
int w,h;
public:
    rectangle(){}
    rectangle(int a,int b):w(a),h(b)
    {

        cout<<"rectangle has been created"<<endl;
 rectangle  ob;
 //rectangle ob2(1,2);infinite loop
    }
    void print();//prototype of function"body outside the class"
    ~rectangle(){

        cout<<"rectangle has been deleted"<<endl;
        cout<<w<<" "<<h<<endl;
    }
    //~rectangle();
};
void rectangle:: print(){
cout<<"body of the prototype of the function is outside the class"<<endl;
cout<<w<<" "<<h<<endl;
}
//rectangle::~rectangle(){body}


int main(){
rectangle r1(3,4),r2(5,6);
rectangle r3;
r1.print();
}
*/



//structures/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
#include <iostream>
#include <cstring>
using namespace std;
struct car{

string name;
string color;
int maxspeed;
int model;

} i,o;//defined the objects outside main
struct ddistance{
int feet;
int inches;
};
ddistance add (ddistance d1,ddistance d2){
ddistance result;
result.feet=d1.feet+d2.feet;
result.inches=d1.inches+d2.inches;
return result;
}


int main()
{
  car g;
  car t={"kia","red",324,2017};//another way to initialized variables in struct
  g.name="kia";//members in a struct accessable in all the program if not specified as private"unlike classes"
  g.model=23;
  cout<<g.name<<endl;
  cout<<t.maxspeed<<endl;
  o.color="blue";
  cout<<o.color<<endl;
  if(g.model>t.maxspeed){
    cout<<"yes";
  }
  else cout<<"no";
ddistance x,y,z;
cin>>x.feet>>x.inches;
cin>>y.feet>>y.inches;
z=add(x,y);
cout<<z.feet<<" "<<z.inches<<endl;


//classes+structs together at the end of the video
}
*/



//pointers///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
#include <iostream>
using namespace std;
int main(){
float var1=9.0;
float *ptr;//pointers do not have a data type
ptr=&var1;
cout<<*ptr<<endl;
*ptr=7.0;//changes done to the *ptr reflects on var1 and vise versa
cout<<*ptr<<endl;
cout<<var1<<endl;
cout<<ptr<<endl;
cout<<&var1<<endl;

void *ptr2;//points to any data type
//you can do arithmetic operations to *ptr
}
*/



//new and delete///////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
#include <iostream>
using namespace std;
int main(){
int *p;
cout<<p<<endl;
p=new int;//alocates "any" address and give to the pointer cause we did not initialize any variables
*p=9;
cout<<*p<<endl;
cout<<p<<endl;
delete p;//delete the space that p took
cout<<p<<endl;
cout<<*p<<endl;
p=new int;//can reuse the pointer
}
*/



//new and delete in classes///////////////////////////////////////////////////////////////////////////////////////////
/*
#include <iostream>
using namespace std;
class rectangle{
int *w,*h;
public:
    rectangle(int ,int);
    ~rectangle();
    int area(){
    return (*w * *h);
    }
};
rectangle::rectangle(int a,int b){
w=new int;
h=new int;
*w=a;
*h=b;
}
rectangle::~rectangle(){
delete w;
delete h;
}
int main(){
rectangle r(2,7);
cout<<r.area();
}
*/



//Array  and Pointers///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
#include <iostream>
using namespace std;
int main(){
int arr[5]={10,50,40,77,33};
cout<<arr<<" "<< *arr <<endl;//address and content of the first element
cout<<arr+0<<endl;//another way
//nameofthearray+index
cout<<arr+2<<endl;
cout<<*(arr+2)<<endl;
//arr is a constant pointer "arr++"not allowed you can not change the value "arr+i"allowed in loops
int *p;
p=arr;//p=&arr[0];
cout<<*p<<endl;
cout<<*(p+1)<<endl;
p+=2;
cout<<*p<<endl;
int *ptr=arr;
for(int i=0;i<5;i++){
    cout<<*ptr<<" ";
    ptr++;
    //if use arr not pointer then you can not do"arr++" cause it is a constant pointer
}
*/



//Array of object and Pointers to Objects//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
#include <iostream>
#include <cstring>
using namespace std;
class student{
char name[40];
int id;
public:
    student(){
    cout<<"empty\n";
    id=0;
    strcpy(name,"no name");
    }
    student(char n[],int iid){
    cout<<"parameterized\n";
    strcpy(name,n);
    id=iid;
    }
    void print(){
    cout<<name<<" "<<id;
    }
};
int main(){
student s1("amira",9),s2("lewis",44);
student arr[3];//array of objects"user(programmer) defined object"
for(int i=0;i<3;i++){
   arr[i].print();
   cout<<endl;
}
student ar[3]={s1,s2};//will not call another constructor because it has been already called"call one default constructor"
student arrr[3]={student("mira",89)};//one parameterized constructor and two empty
student *p;
p=arr;//p=&arr[0];
for(int i=0;i<3;i++){
   (p+i)->print();//arrow instead of dot operator cause it is a pointer
   cout<<endl;
}
}
*/




//enumeration//////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
#include <iostream>
#include <cstring>
using namespace std;
enum days{sat,sun,mon,tue,wed,thur,fri};
enum family{amira=1,toti,aya,sherif};//to start it from 1 not 0
//compiler sees mon for example as"const int mon=2;"
int main(){
days m[7]={sat,sun,mon,tue,wed,thur,fri};

for (int i=0;i<7;i++){
    cout<<m[i]<<" "<<
}
}
*/



//enumeration in classes/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
#include <iostream>
#include <cstring>
using namespace std;
string da[7]={"sat","sun","mon","tue","wed","thur","fri"};
enum days{sat=1,sun,mon,tue,wed,thur,fri};
class week{
days d[7];
public:
    void setdays(days w[]){
    for(int i=0;i<7;i++){
        d[i]=w[i];
    }
    }
    void p(){
        for(int i=0;i<7;i++){
        cout<<"number of day "<<da[i]<<"="<<d[i]<<endl;
    }
    }
};
int main(){
days d[7]={sat,sun,mon,tue,wed,thur,fri};
week g;
g.setdays(d);
g.p();
}
*/




//Static Class Member Static Member Function////////////////////////////////////////////////////////////////////////////////////////
/*
#include <iostream>
#include <cstring>
using namespace std;
void f(){
int x=0;
x++;
cout<<x<<"\n";//"\n"better than endl in time complexity
}
void v(){
 static int x=0;
 x++;
cout<<x<<"\n";//"\n"better than endl in time complexity
}
class student{
static int countt;//common for all abjects of the same class"static class member"
char name[40];
int id;
int first,second,finall,total;
public:
  student(){
  strcpy(name,"no name");
  id=0;
  first=second=finall=0;
  countt++;
  cout<<"number of students is "<<countt<<"\n";
  }
static void printcountt(){
    countt++;
cout<<countt<<"\n";

}
};
int student:: countt=0;
int main(){
f();
f();//1 not 2  not same x " not common" every time the function starts over
v();
v();
v();//static means common same x in all functions and every call affects the other after it
cout<<"////";
student s1,s2,s3;
student st[3];
student k;//traditional way for calling
k.printcountt();
k.printcountt();
student::printcountt();//new way cause it is static and works with static functions only
}
*/




//Constant Object Constant Member Function//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
#include <iostream>
#include <cstring>
using namespace std;
class time{
int h,m,s;
public:
    void print()const{//constant function"right of the prototype"
     cout<<"time is"<<h<<m<<s<<"\n";
    }
time(int i,int j,int k){
h=i;
m=j;
s=k;
}

};
int main(){
const float pi=3.14;
//pi=38;causes error
 const time noon(12,0,0);//constant object can not reach any functions but constant functions
 noon.print();
 time morning(4,0,0);
 morning.print();//not constant object can reach all functions

////use for when we need an object to only call a specific function only or specif group of functions
}
*/



//friend function ,friend clasass
/*
#include <iostream>
#include <cstring>
using namespace std;





int main(){








}
*/




// Operator Overloading "BINARY"///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//apply this to other binary operators (*,/,-)
/*
#include <iostream>
#include <cstring>
using namespace std;
class triangel{
private:
    float width,height;
public:
    triangel(float a=0,float b=0){
    width=a;
    height=b;
    }
    void getdata(){
    cout<<"enter width"<<"\n";
    cin>>width;
    cout<<"enter height"<<"\n";
    cin>>height;
    }
    void sowdata(){
    cout<<"width and height are "<<width<<height<<"\n";
    }
    //objects who call the function do not have dot operator when dealing with its members
   //1
    void add(triangel j,triangel k){

    width=j.width+k.width;
    height=j.height+k.height;
    }
    //2
   triangel addd(triangel k){
       triangel f;
    f.width=width+k.width;
    f.height=height+k.height;
    return f;
    }
    //3
    triangel operator+(triangel k){
       triangel f;
    f.width=width+k.width;
    f.height=height+k.height;
    return f;
    }
};
int main(){
triangel c1,c2(3.5,1.5),c3;
c1.getdata();
c3.add(c1,c2);//first format
c3.sowdata();
c3=c1.addd(c2);//second format "assignment"
c3.sowdata();
c3=c1+c2;//third and simplest format
c3.sowdata();
}
*/





//This
/*
#include <iostream>
#include <cstring>
using namespace std;
//points to the address of the object that called
class stud{
    public:
void address(){
cout<<"address is "<<this<<"\n";
}
};
class student{
int id;
public:
    void setid(int id){
    this->id=id;//to recognize the "class" id not the function id
    }
    void printid(){
    cout<<"id is "<<id<<endl;//here anyway the compiler knows it is the private one not the one in the function cause it can not even see it
    }

};
int main(){
stud a,b,c;
cout<<"address of a "<<&a<<endl;
a.address();
b.address();
c.address();
student st;
st.setid(10);
st.printid();
}
*/





//Operator Overloading/unary Operator//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
#include <iostream>
#include <cstring>
using namespace std;
class unary {
int x,y;
public:
    unary(){}
    unary(int i,int j){
    x=i;  y=j;

    }
    //postfix and prefix without assigning
    /*

    //postfix
    void operator++(int){
    x++;
    y++;

    }

    //prefix
    void operator++(){
    x++;
    y++;

    }


     void show(){
    cout<<x<<" "<<y<<endl;}
    unary& operator++(){
    x++;
    y++;
    return *this;
    /*
    Increments the x and y member variables of the current object (*this).
Returns *this, which is a reference to the updated object.
Usage: When you use ++v;, it increments v and returns v itself (not a copy)

    }
    unary operator++(int){
      unary temp =*this;
    x++;
    y++;
    return temp;
    /*
Creates a temporary copy temp of the current object (*this).
Increments the x and y member variables of *this.
Returns temp, which is the copy of *this before incrementing.
Usage: When you use v++;, it first creates a copy of v, increments v, and then returns the copy (not the updated v)

    }
    unary operator-(){//the binary operator takes parameters
    x= -x;
    y= -y;
    return *this;

}
    bool operator!(){
return (x==0&&y==0);

}
unary operator+=( unary b2){
x+=b2.x;
y+=b2.y;
return b2;

}
};
int main(){
int x=0;
cout<<x++<<" "<<++x<<endl;
//x++ postfix
//++x prefix
cout<<"///////"<<endl;
unary v(10,13),k,l;
/*
v++;
v.show();
++v;
v.show();

k=++v;
k.show();
l=v++;
l.show();
v.show();
unary u(2,3);
-u;
u.show();
if(!v){
    cout<<"yes"<<endl;
}
else cout<<"no"<<endl;
unary b1(1,2);unary b2(3,4);
b1+=b2;//b1.opeartor(b2)
b1.show();
}
*/




//Operator Overloading/Relational Operator/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
#include <iostream>
#include <cstring>
using namespace std;
class relational{
int x,y,z;
public:
  relational(){
  x=y=z=0;
  }

    relational(int i,int j,int k){
        x=i;
        y=j;
        z=k;

    }
    int operator==(relational b){

    return (x==b.x&&y==b.y&&z==b.z);
    //you can change the operators to any relational operator
    }
};


int main(){
relational a(10,14,10),b(10,10,10);
if(a==b){//a.operator==(b);
    cout<<"yes";

}
else cout<<"no";
}
*/





//Operator Overloading/Friend Operator Functions///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
#include <iostream>
#include <cstring>
using namespace std;
class binary{
int x ,y ;
public:
    binary(){}
    binary(int a,int b){
    x=a;y=b;
    }
    binary operator+(binary c2)
    {
        binary c3;
        c3.x=x+c2.x;
        c3.y=y+c2.y;
        return c3;
    }
    void print(){
    cout<<x<<" "<<y<<endl;
    }

    binary operator+(int n)
    {
        binary c3;
        c3.x=x+n;
        c3.y=y+n;
        return c3;
    }

friend binary operator+(binary c1,int n);
friend binary operator+(int n, binary c1);

};

binary operator+(binary c1,int n){
binary c3;
c3.x=c1.x+n;
c3.y=c1.y+n;
return c3;
}
binary operator+(int n, binary c1) {
    binary c3;
    c3.x = c1.x + n;
    c3.y = c1.y + n;
    return c3;
}
int main(){
binary c1(1,4),c2(2,5),c3;
c3=c1+c2;
//c3=c1.operator+(c2);
c3.print();
c3=c1+10;//c3=c1.operator+(10);or c3 = operator+(c1, 10); the second is the friend function "there are two functions that can solve this expression so it appear as an error till you comment one of them
c3.print();
c3=10+c1;//c3 = operator+(10, c1);
c3.print();
return 0;
}
*/






// Operator Overloading/ input,output,int,[]///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
#include <iostream>
#include <cstring>
using namespace std;
namespace different{//we put it due to "reference to distance is ambiguous"error
class distance{
int feet;
int inches;
public:
    distance(){
    feet=0;
    inches=0;

    }
    distance(int f,int i ){
    feet=f;
    inches=i;

    }
 friend istream&operator>>(istream& input,distance& d);
 friend ostream&operator<<(ostream& output,distance& d);
};
istream&operator>>(istream& input,distance& d){
input>>d.feet>>d.inches;
return input;
}
ostream&operator<<(ostream& output,distance& d){
output<<d.feet<<" "<<d.inches;
return output;
}
}

class  number{
int num;
 public:
     number(){
     num=0;
     }
     number(int x){
     num=x;
}

     number(const number&ob){
     num=ob.num;
     }
     int getnum(){
     return num;
     }
     operator int(){
     return int(num);
     }
};

class arr{
int a[3];
public:
    arr(){
    for(int i=0;i<3;i++){
       a[i]=i+2;
    }
    }
    int& operator[](int in){
    return a[in];
    }
};

int main(){
different::distance d1(11,10),d2(5,11),d3;
cin>>d3;//friend not member cause there is no object on the left of the operator
cout<<d3<<endl;//friend not member cause there is no object on the left of the operator
number ob;
int x=10;
ob=x;
cout<<ob.getnum()<<"\n";
int y;
y=ob;
cout<<y<<endl;
arr ob;
cout<<ob[2]<<endl;
ob[2]=20;//after we add reference mark we can modify
cout<<ob[2];
}
*/






//Inheritance part 1///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
class cpolygon{
private:
    int y;
protected :
    int width,height;
public:
    void setvalues(int a,int b){
    width=a;height=b;
    }

};
class crectangle: cpolygon{//private
public:
    cpolygon::setvalues;
   // cpolygon::y;error can not turn base member private into public
    int area(){
        return (width*height);

    }
};
class ctriangel : public cpolygon{//inheritance type is public so it inherit all members as they are but cannot access private ones for sure
    public:
int area(){
return (width*height/2);
}
};
//if inheritance type is not written then it is private"make protected and public members private in the derived class only "
//to return it to its public"does not work if its origin is private" state in the derived"inherited private" class-> public:base::j;

int main(){
crectangle rect;
ctriangel trgl;
rect.setvalues(4,5);
trgl.setvalues(4,5);
cout<<rect.area()<<endl;
cout<<trgl.area()<<endl;
}
*/





//Inheritance 2////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
class mother{
public:
    mother(){
    cout<<"empty mother constructor"<<endl;
    }
    mother(int a){
        cout<<"parametrized constructor mother"<<endl;

    }
};
class father{
};
class daughter:public mother,public father{
public:
    daughter(){
    cout<<"empty daughter constructor"<<endl;
    }
     daughter(int a) :mother(a)// so it inherit the parametrized constructor rather than the empty one
     {
        cout<<"parametrized constructor daughter"<<endl;

    }

};
int main(){
daughter amira(1);//calls empty constructor of mother "base class"

return 0;
}
*/





//polymorphism//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
//base pointer points to the derived class but not  vice versa
//polymorphism all classes inherit from the same class
class cpolygon{
private:
    int y;
protected :
    int width,height;
public:
    void setvalues(int a,int b){
    width=a;height=b;
    }
    virtual int area(void){//virtual function
    //to be able to call area by pointers cause we did not have it here and we got an error
    return(0);
    }

};
class crectangle: public cpolygon{
public:
    int area(void){//emphasis that it does not take ant parameters
        return (width*height);

    }
};
class ctriangel : public cpolygon{
    public:
int area(){
return (width*height/2);
}
};
int main(){
crectangle rect;
ctriangel trgl;
cpolygon *p1,*p2;//polymorphism first step pointers from type the base
p1=&rect;
p2=&trgl;
p1->setvalues(4,5);
p2->setvalues(4,5);
cout<<p1->area()<<endl;// function must be in base class to call it by pointers
cout<<rect.area();
}
*/






//Polymorphism part 2/Abstract Class///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
//base pointer points to the derived class but not  vice versa
//polymorphism all classes inherit from the same class
class cpolygon{
    //abstract class used to define only pointers not even objects
private:
    int y;
protected :
    int width,height;
public:
    void setvalues(int a,int b){
    width=a;height=b;
    }
    virtual int area(void)=0;//pure virtual function"has  no body" that makes the usual class abstract class
    //to be able to call area by pointers cause we did not have it here and we got an error
    void printarea(void){
    cout<<this->area()<<endl;
    }
};
class crectangle: public cpolygon{
public:
    int area(void){//emphasis that it does not take ant parameters
        return (width*height);

    }
};
class ctriangel : public cpolygon{
    public:
int area(){
return (width*height/2);
}
};
int main(){
    crectangle rect;
    ctriangel trgl;
//cpolygon poly    error->abstract class
cpolygon *poly1=&rect;//early binding
cpolygon *poly2=&trgl;
poly1->setvalues(4,5);
poly2->setvalues(4,5);
cout<<poly1->area()<<endl;
cout<<poly2->area()<<endl;
poly1->printarea();
cpolygon *p[2]={&rect,&trgl};
for(int i=0;i<2;i++){
    cout<<p[i]->area()<<endl;//late binding
    p[i]->printarea();

}
}
*/






// Template Function/Templates Function-Templates with Multiple////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
//template<class t>//one data type
template<class t1,class t2>

t2 sum(t1 x,t2 y){//t1 sum return int
return(x+y);
}
int main(){
int x;
double y;
cin>>x>>y;
cout<<sum(x,y)<<endl;
}
*/
/*
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
template<class first,class second>
second smaller(first a,second b){

return(a<b ? a:b);//if a less than b return a else return b
}
int main(){
int x=177;
double y=8.4;
cout<<smaller<double>(x,y)<<endl;//<double> means consider the first double
cout<<smaller<double,int>(x,y)<<endl;//<double,int> means consider the first double the second int
}
*/






//Class template/Template specialization////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

template<class t>
class number{
t first;t second;
public:
    number (t a,t b){
    first =a;
    second=b;
    }
t max();
};
template<class t>//note to repeat it with the function body outside the class
t number<t>::max(){
return (first>second?first:second);
}
int main(){
number<int> ob(10,20);//<data type> must state the type the data will be sent as
cout<<ob.max();
}
*/
//main idea->two ckasses with the same name but each is called based on the data type of the object
/*
template<class t>//class template
class achart{
public:
    achart(t x)
{

    cout<<x<<" is not a character"<<endl;
}
};
template<>//template specialization
class achart<char>{//special class
public:
    achart(char x)
{

    cout<<x<<" is a character"<<endl;
}

};
int main()
{
    achart<int> ob1(7);
    achart <double>ob2(4.6);
    achart<char>ob3('g');//special class



}
*/






//Exception handling///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int main(){
int hour;
//scope try and scope catch must not have any lines between them
try{
cin>>hour;//line we suspect that the user would fail to use it
if (hour<0){
    throw "error";}
    else{
    cout<<" the time is "<<hour<<endl;//else statement without the word else
    }
}
catch( const char*e){
cout<<"wrong value "<<e<<endl;

}
//if throeing two times each with different data type we have to have two catches one for esch
}
*/





//Exception handling/with object//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
class cexception{
int array[100];
public:
    cexception(){
    for(int i=0;i<100;i++)
        array[i]=i;

    }
    int getelement(int x){
    if (x>=100)
        throw xBig();
   else if (x<0)
        throw xSmall();
    else
        return array[x];
    }
    class xBig{
public:
    xBig(){}
    void print(){

    cout<<"too big";
    }

    };
    class xSmall{\
    public:
        xSmall(){}
          void print(){

    cout<<"too small";
    }

    };


};
int main(){
int i;
cexception a;
try{
cout<<"choose element";
cin>>i;
cout<<a.getelement(i)<<endl;
}
catch(cexception::xBig ob){
 ob.print();


}

catch(cexception::xSmall ob){
    ob.print();


}
}
*/
