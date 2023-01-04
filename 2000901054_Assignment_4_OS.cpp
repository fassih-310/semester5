// Name Fassih ur rehman
// reg no  200901054

#include <iostream>
#include<pthread.h>
#include<string>
#include<thread>
using namespace std;
//string str;  
string str;  

void *input_thread(void *arg)
{
    // for input string
  try {
 
    cout << "Enter a string: ";
    cin >> str;
    cout << "You entered: " << str << endl;

    }
   catch (const exception e) {
 
   cout<<"Error.Exception found in input thread:"<<e.what()<<endl;

     }
//return 0 ;
}
void *reverse_thread(void *arg)
{
  // for reverse string
    cout<<"in reverse thread ... THe revers is : "<<endl;
   int len=str.length();

	for(int i=0;i<len;i++)
	{
	cout<<str[len-i-1];
        
	}
cout<<endl;
}

void *capital_thread(void *arg)
{
   // for capatilization 
    cout<<"in capital thread the string is : "<<endl;
    int len=str.length();

	for(int i=0;i<len;i++)
	{
	cout<<(char)toupper(str[i]);
	}
    cout <<endl;
}

void *shift_thread(void *arg)
{
    cout<<"in shift thread the string is : "<<endl;
    for(int i =0 ; i<str.length() ; i++)
    {
    cout<<(char)(str[i]+2);
      }
cout<<endl;
}

int main() {

pthread_t tid1,tid2 , tid3 , tid4 ;
pthread_create(&tid1,NULL,input_thread,(void*)NULL);
pthread_join(tid1,NULL);
pthread_create(&tid2,NULL,reverse_thread,(void*)NULL);

pthread_create(&tid3,NULL,capital_thread,(void*)NULL);

pthread_create(&tid4,NULL,shift_thread,(void*)NULL);


pthread_join(tid2,NULL);
pthread_join(tid3,NULL);
pthread_join(tid4,NULL);


    return 0;
}
