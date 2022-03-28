#include<string.h>
#include<fstream>
#include<cctype>
#include<cstring>
#include<string>
#include<iostream>
#include<math.h>
#include<ctype.h>

using namespace std;

int main (){
    
    int user_choice;
    string plaintext , keyword, encrypted_text, cipherd_text, decrypted_text;
    
    // let the user choose whether he wants encryption or decryption
     
    cout<<"1) encryption\n2) decryption "<<endl;
    cin>>user_choice;
    cin.clear();
    cin.sync();

    //in case of encryption 
    if (user_choice == 1){
        cout<<"encryption"<<endl;

        cout<<"pls enter the message required to be encrypted : "<<endl;
        getline(cin,plaintext);
        
        if(plaintext.length()<80){
        	
        cout<<"pls enter the required keyword :"<<endl;
        getline(cin,keyword);
        
        if(keyword.length()<8){
        	
        //uppercase
        for(int i =0 ; i < plaintext.length() ; i++){
            plaintext[i]=toupper(plaintext[i]);
        }
        
        
        for(int j=0 ; j<keyword.length() ; j++){
            keyword[j]= toupper(keyword[j]);
        }
    

        //overlapping the plaintext with the keyword
        int j=0;
        int x;
            
        for(int i=0 ; i<plaintext.length() ; i++){
            if(isalpha(plaintext[i])){
                encrypted_text[x]=(((plaintext[i])+(keyword[j]))%26) + 65;
                cout<< encrypted_text[x];
                x++;
                j++;
                
                if(j==keyword.length()){
                    j=0;
                } 
             }
            else{
                encrypted_text[x]=plaintext[i];
                cout<<encrypted_text[x];
                x++;
                }
        }
    }
}
  else{
  	cout<<"invalid message(more than 80 char) or keyword length (more than 8 char)";
  }          
       if(user_choice==2){
          	cout<<"decryption"<<endl;
          	cout<<"pls enter the message required to be decrypted :"<<endl;
          	getline(cin,cipherd_text);
          	
          	if(cipherd_text.length()<80){
          	
            cout<<"pls enter the required keyword :"<<endl;
            getline(cin,keyword);
            if(keyword.length()>8){
            	
             //uppercase
            for(int i =0 ; i < cipherd_text.length() ; i++){
            cipherd_text[i]=toupper(cipherd_text[i]);
        }
        
         for(int j=0 ; j<keyword.length() ; j++){
            keyword[j]= toupper(keyword[j]);
        }
            
            //overlapping cipherdmessage with the keyword
            int j=0;
            int x;
            for(int i=0 ; i<cipherd_text.length() ; i++){
            	
            	if(isalpha(cipherd_text[i])){
            		
            		plaintext[x]=((cipherd_text[i]-keyword[j]+26)%26)+65;
            		cout<<plaintext[x];
            		x++;
            		j++;            		
					
            		if( j == keyword.length()){
            			j=0;
					}
            	}
            	
				else{
					plaintext[x]=cipherd_text[i];
					cout<<plaintext[x];
					x++;
				}
            
            }
        }
    }
        
}
    
    return 0;   
}
}
