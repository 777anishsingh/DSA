#include<bits/stdc++.h>
using namespace std;

// ***************************************** CompileTime Polymorphism *****************************************


//1.Function Overloading
class Maths{
    public:

        //Sum fn existing in mmultiple form with different input variables
        int sum(int a,int b){
            cout<<"I'm First signature -> ";
            return a+b;
        }

        int sum(int a,int b,int c){
            cout<<"I'm Second signature -> ";
            return a+b+c;
        } 

        int sum(int a,float b){
            cout<<"I'm Third Signature -> ";
            return a+b+10;
        }
};

//2. Operator Overloading ex: changing + to be used as differnece
class ParaM{

    public:
        int val;

    void operator+(ParaM& obj2){ //operator defined here
        int value1=this->val;
        int value2=obj2.val;
        cout<<(value2-value1)<<endl;

    }
};
 
int main(){

    Maths obj; 

    //cout<<obj.sum(45,34)<<endl<<obj.sum(34,53,12)<<endl<<obj.sum(34,53.36f)<<endl; // use f when we pass float value otherwise it is considered as double value

    ParaM obj1,obj2;
    obj1.val=7;
    obj2.val=2;

    // this should print differnce between them
    obj1 + obj2;

    return 0;
    
}