#include<bits/stdc++.h>
using namespace std;

int main() {
   fstream file;
   string word;
   vector<string>spam_words,nospam_words,all,test; 
   map<string, int> spam,nospam;
   //Reading 1st spam email
   file.open("spam1.txt");
   
   while(file >>word) {
     spam_words.push_back(word);
	 all.push_back(word);
	 spam[word]+=1;
   }
   
   file.close();
   //Reading 2nd spam email
   file.open("spam2.txt");
   
   while(file >>word) {
     spam_words.push_back(word);
	  all.push_back(word);
	  spam[word]+=1;
   }
   
   file.close();
   //Reading 1st non-spam email
   
  file.open("nospam1.txt");
   
   while(file >>word) {
     nospam_words.push_back(word);
	  all.push_back(word);
	  nospam[word]+=1;
   }
   
   file.close();
   //Reading 2nd non-spam email
     file.open("nospam2.txt");
   
   while(file >>word) {
     nospam_words.push_back(word);
	  all.push_back(word);
	  nospam[word]+=1;
   }
   
   file.close();
   //Reading test email
file.open("test.txt");
   
   while(file >>word) {
    test.push_back(word);
   }
   
   file.close();
   
    set<string> vocab(all.begin(),all.end());
   vector<string> :: iterator j;
       cout<<"Total number of Distinct words"<<": "<<vocab.size()<<"\n";
   	cout<<"Total number of Spam words"<<": "<<spam_words.size()<<"\n";
   cout<<"Total number of Non-Spam words"<<": "<<nospam_words.size()<<"\n";
   cout<<endl;


   cout<<endl;

   cout<<"word\t\tnk(spam) nk(non-spam) "<<endl;
    for(j=test.begin();j!=test.end();++j){
   	cout<<*j<<"\t\t"<<spam[*j]<<"\t\t"<<nospam[*j]<<endl;
   }
      cout<<endl;
 float  posterier_spam=0.5;
float posterier_nonspam=0.5;
cout<<"prior_spam-"<<posterier_spam<<"\n"<<"prior_non-spam"<<posterier_nonspam<<endl;
   cout<<endl;
for(j=test.begin();j!=test.end();++j){
    posterier_spam*=(spam[*j]+1)/float(spam_words.size() +vocab.size());
    posterier_nonspam*=(nospam[*j]+1)/float(nospam_words.size() +vocab.size());
}

    cout<<"posterier_spam:"<<posterier_spam<<"\n"<<"posterier_non-spam:"<<posterier_nonspam;
       cout<<endl;
    if(posterier_nonspam>posterier_spam)
    cout<<"\nEmail is NON-SPAM";
else
    cout<<"\nEmail is SPAM";
   return 0;

}

