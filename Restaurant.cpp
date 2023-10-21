#include "main.h"
int cusdesk=0; // So luong khach trong ban
int cusqueue=0; // So luong khach trong hang doi
int cusorder=0; //soluong khach vao ban theo thu tu
class imp_res : public Restaurant
{
	public:	
		imp_res() {};
		customer* desk=NULL; 
		customer* queue=NULL;
		customer* queuehead=NULL;
		customer* order=NULL;
		customer* orderhead=NULL;  
		void RED(string name, int energy)
		{
			
			customer *cus = new customer (name, energy, NULL, NULL);
		
			if(cusdesk<MAXSIZE){										//neu soluong ban be hon maxsize
				if(energy==0){
						return;
					}		
					
					
			customer* checkname=desk;									//checkname trong ban 
			for(int i=0;i<cusdesk;i++){{
				if(checkname->name==name){
					return;
				}
				checkname=checkname->next;
			}}
		
			
			customer* checkname1=queue;									//checkname hang cho
			for(int i=0;i<cusqueue;i++){{
				if(checkname1->name==name){
					return;
				}
				checkname1=checkname1->next;
			}}
		
			
			
			if(order==NULL){											//them vo list thu tu vo ban
					order=cus;
					orderhead=order;
					cusorder++;
				}
			else{
					order->next=new customer(name,energy,NULL,NULL);
					order=order->next;
					cusorder++;
				}											
			if(cusdesk<=MAXSIZE/2){										//neu soluong ban be hon maxsize/2			
					
					
						if(desk==NULL){									//neu ban rong
							desk=cus;
							desk->next=cus;
							desk->prev=desk;
							cusdesk++;
						}
						else{
							if(energy>=desk->energy){					//them chieu thuan
							cus->prev=desk;
							cus->next=desk->next;
							desk->next->prev=cus;
							desk->next=cus;
							desk=cus;
							cusdesk++;
						}
							else if(desk->energy>energy){			//them chieu nghich
							cus->next=desk;
							cus->prev=desk->prev;
							desk->prev->next=cus;
							desk->prev=cus;
							desk=cus;
							cusdesk++;
						}
						}
					
					
				}
			else if(cusdesk>=MAXSIZE/2){									//soluong ban lon hon bang maxsize/2
					int max=0, index=0;
					customer* p=desk;
					for(int i=0;i<cusdesk-1;i++){							//tim vi tri
						int a=abs(p->energy-energy);
						if(a>max){
							max=a;
							index=i;
						}
						p=p->next;
					}
					int b=cus->energy-energy;
					if(b>0){												//them chieu thuan
						for(int i=0;i<index;i++ ){
							desk=desk->next;
						}
							cus->prev=desk;
							cus->next=desk->next;
							desk->next->prev=cus;
							desk->next=cus;
							desk=cus;
							cusdesk++;
					}
					else if(b<0){											//them chieu nghich
						for(int i=0;i<index;i++ ){
							desk=desk->next;
						}
							cus->next=desk;
							cus->prev=desk->prev;
							desk->prev->next=cus;
							desk->prev=cus;
							desk=cus;
							cusdesk++;

					}

				}

			}	
			else if(cusdesk==MAXSIZE){										//soluong ban bang maxsize
				customer* checkname=desk;									//checkname trong ban 
				for(int i=0;i<cusdesk-1;i++){{
				if(checkname->name==name){
					return;
				}
				
				
				checkname=checkname->next;
				}}
		
				customer* checkname1=queue;                                 //checkname hang cho
				for(int i=0;i<cusqueue-1;i++){{
				if(checkname1->name==name){
					return;
				}
				checkname1=checkname1->next;
			}}
			
				
				
				if(cusqueue<MAXSIZE){										//them vao hang doi
					if(cusqueue==0){
					queue=cus;
					queuehead=queue;
					cusqueue++;
				}
					else
					queue->next=cus;
					queue=cus;
					cusqueue++;
				}
				else if(cusqueue==MAXSIZE){
					return;
				}
			}


		cout << name << " " << energy << endl;	
		}
		void BLUE(int num)
		{
			cout << "blue "<< num << endl;
			int after=cusdesk;
			if(num<0){
				return;
			}
			else if(num<cusdesk){						 //num<cusdesk
				for(int i = 0; i < num; i++){						
					for(int j = 0; j < cusdesk; j++ ){				//tim roi xoa desk
						if(desk -> name == order -> name){
							desk->prev->next=desk->next;
							desk->next->prev=desk->prev;
							customer* p=desk;
							desk=desk->next;
							delete p;
							after--;
						}
						else desk=desk->next;
					}
					order=order->next;
				}
			}
			else{										//else
				for(int i=0;i<cusdesk;i++){
					desk->prev->next=desk->next;				//xoa full desk
					desk->next->prev=desk->prev;
					customer* p=desk;
					desk=desk->next;
					delete p;
					desk=desk->next;
					after--;}
				}

			for(int i=after; i<cusdesk; i++){							
				string p = queuehead -> name;						//them tu hang doi vao desk roi xoa hang doi
				int s = queuehead -> energy ;
				queuehead -> prev -> next = queuehead -> next;
				queuehead -> next -> prev = queuehead -> prev;
				customer* newcus = queuehead;
				queuehead = queuehead -> next;
				delete newcus;
				cusqueue--;
				RED(p,s);

				customer* ad=orderhead;
				orderhead=orderhead->next;
				delete ad;											//xoa list
				
				}
		
			
		}
		void PURPLE()
		{
			cout << "purple"<< endl;
		}
		void REVERSAL()
		{
			cout << "reversal" << endl;
		}
		void UNLIMITED_VOID()
		{
			cout << "unlimited_void" << endl;
		}
		void DOMAIN_EXPANSION()
		{
			cout << "domain_expansion" << endl;



		}
		void LIGHT(int num)
		{
			cout << "light " << num << endl;
			cus* new=desk;
			if (desk == nullptr) {
       			return;
    		}
			else{
			if(num>0){															//in thuan
				for(int i=0;i<cusdesk;i++){
				cout<<new->name<<"-"<<new->energy<</n;
				new=new->next;
			}}
			else if(num<0){														//in nguoc
				customer* current = desk;
    			customer* a = nullptr;
    			customer* b = nullptr;

    			do {
        		b = current->next;
        		current->next = a;
        		a = current;
        		current = b;
    			} while (current != desk);
				desk->next = a;
				customer* tail = desk;
    			
				do {
        		cout<<tail->name<<"-"<<tail->energy<</n;
        		tail = tail->next;
    			} while (tail != desk);
			}	
			else{																	//in hang doi
				if (queue== nullptr) {
       			return;
    			}
				for(int i=0;i<cusqueue;i++){
					cout<<queue->name<<"-"<<queue->energy<</n;
					queue=queue->next;
				}
			}

		}
		}
};