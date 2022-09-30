# include <iostream>
using namespace std;

int main()
{
   int x=1;
   int *p;
    p=&x;

  cout<<"\nLa variable x contiene el valor "<<x<<" y esta ubicada en  "<<&x<<endl;
  cout<<"\nLa variable p contiene el valor "<<p<<" y esta ubicada en  "<<&p<<" y *p es "<< *p<<endl;

   *p = 27;

 cout<<"\nLa variable x contiene el valor "<<x<<" y esta ubicada en  "<<&x<<endl;
  cout<<"\nLa variable p contiene el valor "<<p<<" y esta ubicada en  "<<&p<<" y *p es "<< *p<<endl;


   x=31;

  cout<<"\nLa variable x contiene el valor "<<x<<" y esta ubicada en  "<<&x<<endl;
  cout<<"\nLa variable p contiene el valor "<<p<<" y esta ubicada en  "<<&p<<" y *p es "<< *p<<endl;


   return 0;

}
