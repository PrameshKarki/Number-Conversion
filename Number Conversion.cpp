//Conversion of number from one number system to another.
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<cmath>
#include<string.h>
#include<fstream>
using namespace std;
struct Node
{
	int data;
	struct Node * next;

};
struct Node* top=NULL;
void push(int val)
{
	struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
	newnode->data=val;
	newnode->next=top;
	top=newnode;

}

void convertBinary(int num)
{
    int remainder;
	while(num>0)
	{
		remainder=num%2;
		push(remainder);
		num=num/2;
	}
	struct Node *ptr;
	if(top==NULL)
		{
		 cout<<"The Operation is Unsucessfull."<<endl;
         return ;
       }
   else
   {
   	ptr=top;
   	cout<<"     The Binary Number is:";
   	while(ptr!=NULL)
   	{
   		cout<<ptr->data;
   		ptr=ptr->next;
   	}
    cout<<endl;
   }
  top=NULL;
}
void convertOctal(int num)
{
    int remainder;
	while(num>0)
	{
		remainder=num%8;
		push(remainder);
		num=num/8;
	}
	struct Node *ptr;
	if(top==NULL)
		{
		 cout<<"The Operation is Unsucessfull."<<endl;
         return ;
       }
   else
   {
   	ptr=top;
   	cout<<"        The Octal Number Is:";
   	while(ptr!=NULL)
   	{
   		cout<<ptr->data;
   		ptr=ptr->next;
   	}
   	cout<<endl;
    }
  top=NULL;
}
void convertHexa(int num)
{
    int remainder;
	while(num>0)
	{
		remainder=num%16;
		push(remainder);
		num=num/16;
	}
	struct Node *ptr;
	if(top==NULL)
		{
		 cout<<"The Operation is Unsucessfull."<<endl;
         return ;
       }
   else
   {
   	ptr=top;
   	cout<<"The Hexa Decimal Number Is:";
   	while(ptr!=NULL)
   	{
   	    if(ptr->data==10)
   		cout<<'A';
   		else if(ptr->data==11)
   		cout<<'B';
   		else if(ptr->data==12)
   		cout<<'C';
   		else if(ptr->data==13)
   		cout<<'D';
   		else if(ptr->data==14)
   		cout<<'E';
   		else if(ptr->data==15)
   		cout<<'F';
   		else
   		cout<<ptr->data;
        ptr=ptr->next;
   	}
   	cout<<endl;

   }
top=NULL;
}

void convertDecimal(int num)
{
int value=0,remainder,i=0;
while(num>0)
{
remainder=num%10;
value+=remainder*pow(2,i);
num=num/10;
i+=1;
}
cout<<"\nThe Decimal Number Is:"<<value<<endl;
}
void convertOctalToDecimal(int num)
{
int value=0,remainder,i=0;
while(num>0)
{
remainder=num%10;
value+=remainder*pow(8,i);
num=num/10;
i+=1;
}
cout<<"\nThe Decimal Number Is:"<<value<<endl;
}
void convertHexaToDecimal(char validNumber[20])
{ 
    int value=0,temp,i,length;
     length=strlen(validNumber);
     strcpy(validNumber,strrev(validNumber));
     for(i=0;i<length;i++)
	{
		if(validNumber[i]=='A'){
			temp=10;
			value+=temp*pow(16,i);
		}
		else if(validNumber[i]=='B')
		{
			temp=11;
			value+=temp*pow(16,i);
		}
		else if(validNumber[i]=='C')
		{
			temp=12;
			value+=temp*pow(16,i);
		}
		else if(validNumber[i]=='D')
		{
			temp=13;
			value+=temp*pow(16,i);
		}else if(validNumber[i]=='E')
		{
			temp=14;
			value+=temp*pow(16,i);
		}
		else if(validNumber[i]=='F')
		{
			temp=15;
			value+=temp*pow(16,i);
		}
		else
		{
		value+=(validNumber[i]-48)*pow(16,i);//conversion of ascii value to integer
		}
	}
	cout<<"\nThe Decimal Number Is:"<<value<<endl;
}
void aboutMe()
{
ifstream fin;
fin.open("aboutMe.txt");
char str[80];
while(!fin.eof())
{
fin.getline(str,80);
cout<<str<<endl;
}
fin.close();
return ;
}
int main()
{
    int number,choice;
    char validNumber[20];
    do{
	cout<<"-----CONVERSION OF NUMBER FROM ONE NUMBER SYSTEM TO ANOTHER SYSTEM------"<<endl;
	cout<<"[1]Conversion Of Decimal Number Into Binary Number"<<endl;
	cout<<"[2]Conversion Of Decimal Number Into Octal Number"<<endl;
	cout<<"[3]Conversion Of Decimal Number Into Hexa Decimal Number"<<endl;
	cout<<"[4]Conversion Of Binary Number Into Decimal Number"<<endl;
	cout<<"[5]Conversion Of Octal Number Into Decimal Number"<<endl;
	cout<<"[6]Conversion Of Hexa Decimal Number Into Decimal Number"<<endl;
	cout<<"[7]Contct Us"<<endl;
    cout<<"[8]Exit"<<endl;
	cout<<"\n\n\nWhich Operation Do You Want To Perform? ";
	cin>>choice;
	switch(choice)
	{
	case 0:break;
	case 1:cout<<"Enter Any Decimal Number:"<<endl;
           cin>>number;
           convertBinary(number);
           break;
    case 2:cout<<"Enter Any Decimal Number:"<<endl;
           cin>>number;
           convertOctal(number);
           break;
   case 3:cout<<"Enter Any Decimal Number:"<<endl;
           cin>>number;
           convertHexa(number);
           break;
   case 4: 
           {
           TOP:
		   int i,count=0,numberOfDigit=0,tempVar,tempValue=0;
           cout<<"Enter Any Binary Number:";
           for(i=0;;)
           {
           char a=getch();
           cout<<a;
           if(a=='0' || a=='1')
              {
              validNumber[i]=a;
              i++;
              numberOfDigit++;
              }
            else if(a=='\r')
                    {
                    validNumber[i]='\0';
                    break;
                    }
            else
                      count++;
             } 
              if(count==0){
              	
			  for(i=0;i<numberOfDigit;i++)
                  {
              tempVar=validNumber[i]-48;
              tempValue+=tempVar*pow(10,numberOfDigit-i-1);
			  }
			  convertDecimal(tempValue);
              }
            else
            {
                cout<<"Binary Number Only Contains Zero(0) and One(1)."<<endl;
                cout<<"Please Enter Valid Number"<<endl;
                getch();
                system("cls");
                goto TOP;
              }
              break;
            }
            
            

  case 5:  {
           TOP1:
		   int i,count=0,numberOfDigit=0,tempVar,tempValue=0;
           cout<<"Enter Any Octal Number:";
           for(i=0;;)
           {
           char a=getch();
           cout<<a;
           if(a>='0' && a<='7')
              {
              validNumber[i]=a;
              i++;
              numberOfDigit++;
              }
            else if(a=='\r')
                    {
                    validNumber[i]='\0';
                    break;
                    }
            else
                      count++;
             } 
              if(count==0){
              	
			  for(i=0;i<numberOfDigit;i++)
                  {
              tempVar=validNumber[i]-48;
              tempValue+=tempVar*pow(10,numberOfDigit-i-1);
			  }
			  convertOctalToDecimal(tempValue);
              }
            else
            {
                cout<<"Octal Number Contains Number Between Zero(0) And Seven(7) Only."<<endl;
                cout<<"Please Enter Valid Number"<<endl;
                getch();
                system("cls");
                goto TOP1;
              }
              break;
            }
            
  case 6:   {
           TOP2:
		   int i,count=0,numberOfDigit=0,tempVar,tempValue=0;
           cout<<"Enter Any Hexa Decimal Number:";
           for(i=0;;)
           {
           char a=getch();
           cout<<a;
           if(a>='0' && a<='9')
              {
              validNumber[i]=a;
              i++;
              numberOfDigit++;
              }
            else if(a>='A'&& a<='F')
            {
             validNumber[i]=a;
              i++;
          }
            else if(a=='\r')
                    {
                    validNumber[i]='\0';
                    break;
                    }
            else
                      count++;
             } 
              if(count==0){
			  convertHexaToDecimal(validNumber);
		     }
              else
            {
                cout<<"Hexa Decimal Number Contains Number Between Zero(0) And Seven(9) And Alphabets A-F Only."<<endl;
                cout<<"Please Enter Valid Number"<<endl;
                getch();
                system("cls");
                goto TOP2;
              }
              break;
            }
            
  case 7:system("CLS");
         cout<<"\n\n\n";
		       aboutMe();
		        break;
  case 8:  system("cls");
           cout<<"Thank You!!!"<<endl;
           exit(0);
           break;
 default:cout<<"Invalid Choices"<<endl;
  }}
    while(choice!=0);
    return 0;
}
//This Code Was Sucessfully Compiled In Windows 10
//Pramesh Karki


