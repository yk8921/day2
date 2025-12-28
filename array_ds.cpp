#include<iostream>
using namespace std;

class list{
	private:
		int *arr, size, len, *curr;
	
	public:
		list(int s){
			arr=new int[s];
			size=s;
			len=0;
			curr=nullptr;
		}
		
	void start(){
		curr=arr;
	}
	
	void end(){
		curr=arr+len-1;
	}
	
	void back(){
		curr--;
	}
	
	void next(){
		curr++;
	}
	
	void insert(int val, int pos){
		if(len==size){
			cout<<"List is Full!";
			return;
		}
		
		if(pos<1 || pos>len+1){
			cout<<"Invalid Position!";
			return;
		}
		
		end();
		
		for(int i=len; i>=pos; i--){
			*(curr+1)=*curr;
			back();
		}
		
		*(curr+1)=val;
		len++;
		cout<<val<<" is inserted at the position "<<pos<<endl<<endl;
	}
	
	
	void remove(int pos){
		if(len==0){
			cout<<"Empty List!";
			return;
		}
		
		if(pos<0 || pos>len){
			cout<<"Invalid Position!";
			return;
		}
		
		curr=arr+pos-1;
		
		for(int i=pos; i<len; i++){
			*curr=*(curr+1);
			next();
		}
		
		len--;
	}
	
	
	int get(int pos){
		if(len==0){
			cout<<"Empty List!";
			return true;
		}
		
		if(pos<0 || pos>len){
			cout<<"Invalid Position!";
			return true;
		}
		
		curr=arr+pos-1;
		return *curr;
		
	}
	
	void update(int val, int pos){
		if(len==0){
			cout<<"Empty List!";
			return;
		}
		
		if(pos<0 || pos>len){
			cout<<"Invalid Position!";
			return;
		}
		
		curr=arr+pos-1;
		*curr=val;
		
	}
	
	int getlen(){
		return len;
	}
	
	void clear(){
		len=0;
	}
	
	bool find(int val){
		if(len==0){
			return true;
		}
		
		for(int i=0; i<=len; i++){
			if(*curr==val){
				return val;
			}
			next();
		}
		return false;
	}
	
	
	void copy(list l){
		if(l.getlen()==0){
			cout<<"Empty!"; return;
		}
		
		for(int i=0; i<=l.getlen(); i++){
			int val=l.get(i);
			insert(val, i);
		}
	}
	
	void printt(){
		if(len == 0){
        cout << "List is empty" << endl;
        return;
    }
    
    curr=arr;
    
    for(int i=0; i<len; i++){
    	cout<<*(curr+i)<<" ";
	}
	return;

}

//	void sort(){
//		if(len==size){
//			cout<<"List is Full!";
//			return;
//		}
//		
//		curr=arr;
//		int *tempp=curr+1;
//		
//		for(int i=0; i<=len; i++){
//			if(*(curr+i)>*tempp){
//				int temp=*curr;
//				*curr=*tempp;
//				*tempp=temp;
//			}
//			tempp++;
//		}
//		return;
//	}

	~list(){
		delete[] arr;
	}


	
};


int main(){
	list l1(5);
	l1.insert(1,1);
	l1.insert(2,2);
	l1.insert(3,3);
	l1.insert(4,4);
	
	cout<<endl<<endl<<endl;
	l1.printt();
	
	cout<<endl<<endl<<endl;
	
	
	return 0;
}