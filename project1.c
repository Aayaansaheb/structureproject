#include<stdio.h>
#include<string.h>
#define TRANSACTION_ID 10
#define BUYER_ID 10
#define SELLER_ID 10
#define SUCCESS 1
#define FAILURE 0
#define DB_SIZE 100
#define TIME 20
typedef struct Timestamp{
    int date;
    int month;
    int year;
    int hour;
    int minute;
}TS;
typedef struct Transactions{
    char TrId[TRANSACTION_ID];
    char BuyerId[BUYER_ID];
    char SellerId[SELLER_ID];
    float energy;
    float price;
    TS datetime;
    
    
}tr;
typedef struct seller_transactions{
    char seller_id[10];
    float revenue;
}st;
void initialise_db(tr records[]){
    for(int i=0;i<DB_SIZE;i++){
        records[i].TrId[0]='\0';
        records[i].BuyerId[0]='\0';
        records[i].SellerId[0]='\0';
        records[i].energy=0;
        records[i].price=0;
        records[i].datetime.date=0;
        records[i].datetime.month=0;
        records[i].datetime.year=0;
        records[i].datetime.hour=0;
        records[i].datetime.minute=0;
        
    }
}
int Insert_Update(tr records[],int size,char tr_id[],char buy_id[],char sell_id[],float energy,float price,int date,int month, int year,int hour,int minute)
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
    }
    
        if(found)
        {
            strcpy(records[i].BuyerId,buy_id);
            strcpy(records[i].SellerId,sell_id);
            records[i].energy=energy;
            records[i].price=price;
            records[i].datetime.date=date;
            records[i].datetime.month=month;
            records[i].datetime.month=year;
            records[i].datetime.month=hour;
            records[i].datetime.month=minute;
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
                records[i].energy=energy;
                records[i].price=price;
                records[i].datetime.date=date;
                records[i].datetime.month=month;
                records[i].datetime.month=year;
                records[i].datetime.month=hour;
                records[i].datetime.month=minute;
            }
            else
            status_code= FAILURE;
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
         printf("timestamp: %d/%d/%d   %d:%d",records[i].datetime.date,records[i].datetime.month,records[i].datetime.year,records[i].datetime.hour,records[i].datetime.minute);
         i++;
    }
}
int FindMaxTransactionMonth(tr records[],int size)
{
    int arr[12]={0};
    int i=0;
    while(records[i].TrId[0]!='\0'&&(i<size))
    {
        arr[records[i].datetime.month-1]++;
        i++;
    }
    int max=arr[0];
    for(int j=0;j<12;j++)
    {
        if(max<arr[j])
        max=arr[j];
    }
    for(int j=0;j<12;j++)
    {
        if(max==arr[j])
        {
           switch(j)
           {
            case 1:
                printf("Maximum transactions occured in January");
                break;
            case 2:
                printf("Maximum transactions occured in February\n");
                break;
            case 3:
                printf("Maximum transactions occured in March\n");
                break;
            case 4:
                printf("Maximum transactions occured in April\n");
                break;
            case 5:
                printf("Maximum transactions occured in May\n");
                break;
            case 6:
                printf("Maximum transactions occured in July\n");
                break;
            case 7:
                printf("Maximum transactions occured in August\n");
                break;
            case 8:
                printf("Maximum transactions occured in September\n");
                break;
            case 9:
                printf("Maximum transactions occured in october\n");
                break;
            case 10:
                printf("Maximum transactions occured in November\n");
                break;
            case 11:
                printf("Maximum transactions occured in December\n");
                break;
           }
                    

        }
    }
    

}
void list_of_sellers(tr records[],int size)
{
    int j=0,unique_sellers=0;
    st revenue_arr[100];
    int found=0;
    for(int i=0;i<100;i++)
    {
        revenue_arr[i].seller_id[0]='\0';
        revenue_arr[i].revenue=0;
    }
    while(j<size)
    {
        int i=0;
        while((revenue_arr[i].seller_id!='\0')&&(!found))
        {
            if(strcmp(revenue_arr[i].seller_id,records[j].SellerId)==0)
            found=1;
            else
            i++;
        }
        if(!found)
        {
            i=0;
            while(revenue_arr[i].seller_id[0]!='\0')
            {
                i++;
            }
            strcpy(revenue_arr[i].seller_id,records[j].SellerId);
            revenue_arr[i].revenue=total_seller_revenue(records,DB_SIZE,records[j].SellerId);
            unique_sellers+=1;
        }
        j++;
    }
    
}
int main(){
    int i;
    float energy,price;
    char transaction_id[TRANSACTION_ID];
    char buyer_id[BUYER_ID];
    char seller_id[SELLER_ID];
    tr grid_db[DB_SIZE];
    initialise_db(grid_db);
    printf("Enter the number in front of the the operation that you want to perform");
    return 0;
    
}
