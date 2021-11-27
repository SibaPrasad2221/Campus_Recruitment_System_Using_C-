#include<bits/stdc++.h>
#include<windows.h>

using namespace std;
struct Node{
  string name,course,pro_lan;
  int id,regd_no;
  int new_entry_count;
  Node * next;
};
int id=107, c=0;
Node * head=NULL;
void valid_user();
void new_user();
void login(string, int);

void display(Node * nw){
  int temp=0;
  cout<<"\n\t\tExisting Record\n";
  cout<<"\t\tRecord_ID    Name    Regd No   Course&Stream   Programing Language\n";
  cout<<"\t\t---------    ----    -------   -------------   -------------------\n";
  while(nw!=NULL){
    cout<<"\t\t"<<nw->id<<"\t     "<<nw->name<<"\t"<<nw->regd_no<<"\t"<<nw->course<<"          "<<nw->pro_lan<<"\n";
    cout<<"\t\t---------    ----    -------   -------------   -------------------\n";
    nw=nw->next;
    temp += 1;
  }
  if(temp==0){
    cout<<"\n\t\tNo record found!! :(";
    temp=0;
  }
  new_user();
}

void displayByRecord(Node * nw,int org_id){
  int temp=0;
  while(nw->id!=org_id){
    nw=nw->next;
    temp += 1;
  }
  cout<<"\n\t\tBelow, your all details are mentioned! ";
  cout<<"\n\t\tID: "<<nw->id;
  cout<<"\n\t\tName: "<<nw->name;
  cout<<"\n\t\tRegd Number: "<<nw->regd_no;
  cout<<"\n\t\tCourse/Stream: "<<nw->course;
  cout<<"\n\t\tProgramming Languages: "<<nw->pro_lan;
  cout<<"\n\t\tThank You! ";
  if(temp==0){
    cout<<"\n\t\tNo record found!! :(";
  }
  new_user();
}

void newRecord(Node ** head,int id,string name,string course,int regd_no,string pro_lan){
  Node * nw=new Node;
  nw->id=id;
  nw->name=name;
  nw->course=course;
  nw->regd_no=regd_no;
  nw->pro_lan=pro_lan;
  nw->next= * head;
  * head=nw;
}

void modifyRecord(Node * nw,int org_id,int mod_data_res){
  string mod_nm,mod_course,mod_pro_lan;
  int mod_reg_no;
  while(nw->id!=org_id){
    nw=nw->next;
  }
  if(mod_data_res==1){
    cout<<"\n\t\tEnter the new name that You want to update:  ";
    cin>>mod_nm;
    nw->name=mod_nm;
  }else if(mod_data_res==2){
    cout<<"\n\t\tEnter the new course name that You want to update:  ";
    cin>>mod_course;
    nw->course=mod_course;
  }else if(mod_data_res==3){
    cout<<"\n\t\tEnter the new registration number that You want to update:  ";
    cin>>mod_reg_no;
    nw->regd_no=mod_reg_no;
  }else if(mod_data_res==4){
    cout<<"\n\t\tEnter the new programming language that You want to update: ";
    cin>>mod_reg_no;
    nw->regd_no=mod_reg_no;
  }
  cout<<"\n\n\t\tYour data has been updated successfully! :)\n";
  cout<<"\n\t\tPlease Wait ";
  for(int i=0;i<3;i++){
     cout<<".";
     Sleep(1000); //1000 milisecond is 1 second
  }
  system("CLS");
  new_user();
}

void delete_Record(Node ** head,int id){
  Node * temp= *head;
  Node * previous;

  // //calculate size of linked list
  // int size = 0;
  //
  // while (node != NULL) {
  //     node = node -> next;
  //     size++;
  // }

  if (id < 101) {
       cout << "Enter valid record id \n";
       return;
  }
  if (id == 101) {
       * head = temp -> next; //changing head to next in the list
       cout << "Record with id "<< temp->id<<" deleted successfully! " <<endl;
       free(temp);
       return;
   }
   //run until we find the value to be deleted in the list
  while (temp->id!=id) {
      //store previous link node as we need to change its next val
      previous = temp;
      temp = temp -> next;
  }
  previous -> next = temp -> next;
  cout << "\n\t\tRecord with id "<< temp->id<<" deleted successfully! " <<endl;

  //free(temp);
  cout<<"\n\t\tPlease Wait ";
  for(int i=0;i<3;i++){
    cout<<".";
    Sleep(1000); //1000 milisecond is 1 second
  }
  system("CLS");
  new_user();
}

void new_user(){
  string ch,name;
  int psd,c3,c4;
  cout<<"\n\t======================================================================";
  cout<<"\n\t||\t\t\t\t\t\t\t\t    ||";
  cout<<"\n\t||\t\t\t\t\t\t\t\t    ||";
  cout<<"\n\t||\t\t\tCAMPUS RECRUITMENT SYSTEM\t\t    ||";
  cout<<"\n\t||\t\t\t\t\t\t\t\t    ||";
  cout<<"\n\t||\t\t\t\t\t\t\t\t    ||";
  cout<<"\n\n\t\tSIGN UP: ";
  cout<<"\n\n\n\n\t\t<IF YOU ARE THE ADMIN PUT ' ' YOUR PASSCODE> ELSE PUT '#' \n\t\t";
  cin>>ch;
  if(ch=="#"){
    cout<<"\n\t\tEnter Name: ";
    cin>>name;
    cout<<"\n\t\tEnter Password: ";
    cin>>psd;
    cout<<"\n\t\tYour ID is creating please wait";
    for(int i=0;i<4;i++){
      cout<<".";
      Sleep(1000); //1000 milisecond is 1 second
    }
    cout<<"\n\t\tYour id created successfully :)"<<endl;
    system("CLS"); //it will clear all previous record before it but it hold the record what it had before
    login(name,psd);
  }else{
    if(ch=="Admin2221"){
      cout<<"\n\t\t<1> Show All profiles\n\t\t<2> Delete Any profile\n\t\t<3> Modify Any profile: \n";
      cin>>c3;
      if(c3==1){
        display(head);
      }else{
        cout<<"\n\t\tEnter ID number which you want to delete: \n\t\t(IF you don't know the id, view in the database)";
        cin>>c4;
        //display(head);
        delete_Record(&head,c4);
      }
    }else{
      system("CLS");
      cout<<"\n\n\t\tYour Admin passcode is incorrect!!!";
      for(int i=0;i<4;i++){
         cout<<".";
         Sleep(1000); //1000 milisecond is 1 second
      }
      system("CLS");
      new_user();
    }
  }
}
void valid_user(){
  int response,res2,reg,org_id,mod_data_res;
  string nm,cr_st,pl;
  cout<<"\n\n\t\tCampus Recruitment System"<<endl;
  cout<<"\n\n\t\t<1>Create/Modify Profile\n\t\t<2>Show Profile\n\t\t<3>Exit\n";
  cin>>response;
  if(response==1){
    cout<<"\n\t\t<1> Create\n\t\t<2> Modify\n";
    cin>>res2;
    if(res2==1){
      cout<<"\n\t\tEnter The Below details Correctly (without space) ";
      cout<<"\n\t\tRegistration Number: ___";
      cin>>reg;
      cout<<"\n\t\tFull Name: ___";
      cin>>nm;
      cout<<"\n\t\tCourse and Stream: ___";
      cin>>cr_st;
      cout<<"\n\t\tProgramming Languages you know: ___";
      cin>>pl;
      newRecord(&head,id,nm,cr_st,reg,pl); //create a new profile
      cout<<"\n\t\tPlease Wait ";
      for(int i=0;i<3;i++){
        cout<<".";
        Sleep(1000); //1000 milisecond is 1 second
      }
      system("CLS");
      cout<<"\n\n\t\tYour Data has been submitted successfully with Profile id "<<id<<" :)";
      id += 1;
      cout<<"\n\n\t\t<1>Modify Profile\n\t\t<2>Show Profile\n\t\t<3>Exit\n";
      cin>>response;
      if(response==1){
        cout<<"\n\n\t\tEnter Profile id: ";
        cin>>org_id;
        cout<<"\n\n\t\tTo change any details put,\n\t\t1---->For Name\n\t\t2---->For Course You have registered\n\t\t3---->For Registration no you have\n\t\t4---->For Programming Language you have given\n ";
        cin>>mod_data_res;
        modifyRecord(head,org_id,mod_data_res);
      }
      else if(response==2){
        cout<<"\n\t\tEnter Your '''Record_ID''' to see your profile details: ";
        cin>>org_id;
        displayByRecord(head,org_id);
      }else{
        new_user();
      }
    }else if(res2==2){
      cout<<"\n\t\tEnter Your '''Record_ID''' to see your profile details:";
      cin>>org_id;
      cout<<"\n\t\tTo change any details put,\n\t\t1---->For Name\n\t\t2---->For Course You have registered\n\t\t3---->For Registration no you have\n\t\t4---->For Programming Language you have given\n ";
      cin>>mod_data_res;
      modifyRecord(head,org_id,mod_data_res);
    }else{
      cout<<"\n\t\tYou have chosen a wrong option!";
    }
    int ret;
    cout<<"\n\n";
    cout<<"\n\t\t\t\t1. Logout\n\t\t\t\t2. Previous Menu\n\t\t\t\t3. Exit ";
    cin>>ret;
    if(ret==1){
      new_user();
    }else if(ret==2){
      valid_user();
    }else{
      exit(0);
    }

  }else if(response==2){
    cout<<"\n\t\tEnter Your '''Record_ID''' to see your profile details:";
    cin>>org_id;
    displayByRecord(head,org_id);
  }else{
    new_user();
  }
}

void login(string name,int psd){
  string n; int p;
  cout<<"\n\n\t\tCampus Recruitment System"<<endl;
  cout<<"\n\n\t\tPLEASE LOGIN"<<endl;
  cout<<"\n\n\t\tEnter name: ";
  cin>>n;
  cout<<"\n\n\t\tEnter password: ";
  cin>>p;
  if(n==name && p==psd){
    cout<<"\n\t\tLogin successfully :) ";
    system("CLS");
    valid_user();
  }else{
    system("CLS");
    cout<<"\n\t\tWrong Credential(s), Try again :(";
    login(name,psd);
    while(c!=3){
      c+=1;
      new_user();
    }
    cout<<"\n\t\tMaximum Login Attempts, Try again later. :(";
  }
}
int main(){
  //dummy record
  newRecord(&head,100,"Siba","Btech/CSE",138,"C++,Python");
  newRecord(&head,101,"Deepak","Btech/CSE",127,"C++,C");
  newRecord(&head,102,"Rashmi","Btech/ECE",203,"C");
  newRecord(&head,103,"Jagan","Btech/Civil",99,"C#,Java");
  newRecord(&head,104,"Prabin","Btech/CSE",118,"Python,c");
  newRecord(&head,105,"Suresh","Btech/EEE",304,"Java,Python");
  newRecord(&head,106,"Mangal","Btech/Aero",311,"Python,C");
  new_user();
}
