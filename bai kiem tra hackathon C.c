#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//ham kiem tra so nguyen to
int prime(int n){
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			return 0;
		}
	}
	return n>1;
}
//ham sap xep tang dan
void incSort(int a[],int x,int n){
	for(int i=x;i<n-1;i++){
		int min_pos=i;
		for(int j=i+1;j<n;j++){
			if(a[j]<a[min_pos]){
				min_pos=j;
			}
		}
		int temp=a[i];
		a[i]=a[min_pos];
		a[min_pos]=temp;
	}
}
//ham sap xep giam dan
void ascSort(int a[],int n){
	for(int i=0;i<n-1;i++){
		int min_pos=i;
		for(int j=i+1;j<n;j++){
			if(a[j]>a[min_pos]){
				min_pos=j;
			}
		}
		int temp=a[i];
		a[i]=a[min_pos];
		a[min_pos]=temp;
	}
}

int main(){
	//khai bao mang 100 phan tu
	int arr[100];
	int n;
	int currentIndex=0;
	int sum,cntPositive,cntPrime;
	int k,m;
	int index1,index2;
	int new_arr[100];
	do{
		//in menu
	    printf("\n***************MENU****************\n");
	    printf("1.Nhap gia tri n phan tu cua mang\n");
	    printf("2.In gia tri phan tu cua mang\n");
	    printf("3.Tinh trung binh cac phan tu duong cua mang\n");
	    printf("4. In ra chi so cac phan tu co gia tri bang k trong mang\n");
	    printf("5.Su dung thuat toan sap xep noi bot sap xep mang giam dan\n");
	    printf("6.Tinh so luong cac phan tu la so nguyen to trong mang\n");
	    printf("7.Sap xep cac phan tu chan chia het cho 3 o dau mang theo thu tu tang dan,cac phan tu le chia het cho 3 o cuoi mang theo thu tu giam dan,ca phan tu con lai o giua mang theo thu tu tang dan\n");
	    printf("8.Nhap gia tri m tu ban phim, chen gia tri m vao mang(sap xep giam dan) dung vi tri\n");
	    printf("9.Thoat\n");
	    //chon menu
		int choice;
	    printf("Lua chon cua ban la: ");
	    scanf("%d",&choice);
	    switch(choice){
	    	case 1:
	    		printf("Nhap gia tri n: ");
	    		scanf("%d",&n);
	    		for(int i=0;i<n;i++){
	    			printf("Nhap gia tri arr[%d]=",currentIndex);
	    			scanf("%d",&arr[currentIndex]);
	    			currentIndex++;
				}
	    		break;
	    	case 2:
	    		printf("Gia tri cac phan tu trong mang la: ");
	    		for(int i=0;i<currentIndex;i++){
	    			printf("%d\t",arr[i]);
				}
	    		break;
	    	case 3:
	    		sum=0;
	    		cntPositive=0;
	    		for(int i=0;i<currentIndex;i++){
	    			if(arr[i]>0){
	    				sum+=arr[i];
	    				cntPositive+=1;
					}
				}
				printf("Gia tri trung binh phan tu duong cua mang la: %.2f",(float)sum/cntPositive);
	    		break;
	    	case 4:
	    		//nhap gia tri k
	    		printf("Nhap gia tri k:");
	    		scanf("%d",&k);
	    		//kiem tra  va in phan tu co gia tri bang k
	    		for(int i=0;i<currentIndex;i++){
	    			if(arr[i]==k){
	    				printf("Phan tu co chi so %d cua mang co gia tri bang %d\n",i,k);
					}
				}
	    		break;
	    	case 5:
	    		for(int i=0;i<currentIndex;i++){
	    			for(int j=0;j<currentIndex-i-1;j++){
	    				if(arr[j]<arr[j+1]){
	    					int temp=arr[j];
	    					arr[j]=arr[j+1];
	    					arr[j+1]=temp;
						}
					}
				}
	    		break;
	    	case 6:
	    		cntPrime=0;
	    		for(int i=0;i<currentIndex;i++){
	    			if(prime(arr[i])){
	    				cntPrime+=1;
					}
				}
				printf("So phan tu la so nguyen to trong mang la: %d",cntPrime);
	    		break;
	    	case 7:
	    		index1=-1;
	    		index2=currentIndex;
	    		//sap xep tang dan phan tu chia het cho 3 ve dau mang
	    		for(int i=0;i<currentIndex;i++){
	            int min_pos,j,check=0;
	            for(j=i;j<currentIndex;j++){
		            if(arr[j]%3==0&&arr[j]%2==0){
			        check=1;
	    	        min_pos=j;
	    	        break;
	                }
                }
                if(check){
                	index1++;
    	            for(j=i+1;j<currentIndex;j++){	
	   		            if(arr[j]%3==0&&arr[j]%2==0&&arr[j]<arr[min_pos]){
			                min_pos=j;
		                }		
	                }
	                int temp=arr[i];
		            arr[i]=arr[min_pos];
		            arr[min_pos]=temp;
	            }
                }
                //sap xep phan tu le chia het cho 3 o cuoi mang theo thu tu giam dan
                for(int i=currentIndex-1;i>=0;i--){
	            int min_pos,j,check=0;
	            for(j=i;j>=0;j--){
		            if(arr[j]%3==0&&arr[j]%3==1){
			        check=1;
	    	        min_pos=j;
	    	        break;
	                }
                }
                if(check){
                	index2--;
    	            for(j=i-1;j>=0;j--){	
	   		            if(arr[j]%3==0&&arr[j]%2==1&&arr[j]<arr[min_pos]){
			                min_pos=j;
		                }		
	                }
	                int temp=arr[i];
		            arr[i]=arr[min_pos];
		            arr[min_pos]=temp;
	            }
                }
                // sap xep phan tu o giua tang dan
                incSort(arr,index1,index2);
                //in mang da sap xep
                for(int i=0;i<currentIndex;i++){
                	printf("%d\t",arr[i]);
				}
	    		break;
	    	case 8:
			// sap xep mang giam dan
			printf("Mang sap xep giam dan la:");	    		
	    		ascSort(arr,currentIndex);
	    		for(int i=0;i<currentIndex;i++){
	    			printf("%d\t",arr[i]);
				}
	    	//nhap vao gia tri m
				printf("\nNhap gia tri m: ");
				scanf("%d",&m);
				if(m<arr[currentIndex-1]){
					arr[currentIndex]=m;
				}else{
					for(int i=0;i<currentIndex;i++){
					if(m>arr[i]){
						for(int j=currentIndex;j>i;j--){
							arr[j]=arr[j-1];
						}
						arr[i]=m;
						break;
					}
				}
				}				
				currentIndex++;
				printf("\nMang sau khi chen phan tu la:");
				for(int i=0;i<currentIndex;i++){
	    			printf("%d\t",arr[i]);
				}
	    		break;
	    	case 9:
	    		exit(0);
	    	default:
	    		printf("Lua chon tu 1 den 9");
		}
	}while(1==1);
	
}
