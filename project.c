#include<stdio.h>
#include<string.h>
#define TRANSACTION_ID 10
#define BUYER_ID 10
#define SELLER_ID 10
#define SUCCESS 1
#define FAILURE 0
#define DB_SIZE 100
#define TIME 20
typedef struct Transactions{
    char TrId[TRANSACTION_ID];
    char BuyerId[BUYER_ID];
    char SellerId[SELLER_ID];
    float energy;
    float price;
    char timestamp[TIME];
    
}tr;
void initialise_db(tr records[],int size){
    for(int i=0;i<DB_SIZE;i++){
        records[i].TrId[0]='\0';
        records[i].BuyerId[0]='\0';
        records[i].SellerId[0]='\0';
        records[i].energy=0;
        records[i].price=0;
    }
}
int Insert_Update(tr records[],int size,char tr_id[],char buy_id[],char sell_id[],char time[],float energy,float price)
{
    int status_code=SUCCESS;
    int i,j,found,is_free_loc;
    i=0,found=0;
    while((i<size)&&!found)
    {
        if(strcmp(records[i].TrId,tr_id)==0)
        {
            found=1;
        }
        else
         i++;
    
        if(found)
        {
            strcpy(records[i].BuyerId,buy_id);
            strcpy(records[i].SellerId,sell_id);
            strcpy(records[i].timestamp,time);
            records[i].energy=energy;
            records[i].price=price;
        }
        else
        {
            j=0;
            is_free_loc=0;
            while((j<size)&&(is_free_loc==0))
            {
                if(records[i].TrId[0]=='\0')
                is_free_loc=1;
                else
                j++;
            }
            if(is_free_loc==1)
            {
                strcpy(records[i].TrId,tr_id);
                strcpy(records[i].BuyerId,buy_id);
                strcpy(records[i].SellerId,sell_id);
                strcpy(records[i].timestamp,time);
                records[i].energy=energy;
                records[i].price=price;
            }
            else
            status_code= FAILURE;
        }
    }
    return status_code;

}
void View_Transactioins(tr records[], int size)
{
    int i=0;
    while((i<size))
    {
         printf("\n");
         printf("Transaction id   : %s\n",records[i].TrId);
         printf("Buyer Id         : %s\n",records[i].BuyerId); 
         printf("Seller Id        : %s\n",records[i].SellerId);
         printf("Amount of Energy : %f\n",records[i].energy);
         printf("Selling price    : %f\n",records[i].price);
         printf("Timestamp        : %s\n",records[i].timestamp);
         i++;
    }
}
int main(){
    int i;
    float energy,price;
    char transaction_id[TRANSACTION_ID];
    char buyer_id[BUYER_ID];
    char seller_id[SELLER_ID];
    tr grid_db[DB_SIZE];
    initialise_db(grid_db,DB_SIZE);
    printf("Enter the number in front of the the operation that you want to perform");
    printf("")
    return 0;
    
}
