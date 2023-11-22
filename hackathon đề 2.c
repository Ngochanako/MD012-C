#include<stdio.h>
#include<stdlib.h>

int main(){
	int choice;
	
		int cnt,n,m;
		printf("Nhap so phan tu cua hang:");
	    scanf("%d",&n);
	    printf("Nhap so phan tu cua cot:");
	    scanf("%d",&m);
	    int arr[n][m];
	    int row;
	    int a[m];
//	    int new_arr[row][m];
//	    int new_arr1[n+1][m];
	do{
		printf("\n**********MENU**********\n");
		printf("1.Nhap gia tri phan tu cua mang\n");
		printf("2.In gia tri phan tu mang theo ma tran\n");
		printf("3.Tinh so luong phan tu chia het 2 va 3 trong mang\n");
		printf("4.In cac phan tu va tong cac phan tu nam tren duong bien,duong cheo chinh va duong cheo phu\n");
		printf("5.Su dung thuat toan sap xep chon sap xep phan tu tang dan theo cot cua mang\n");
		printf("6.In ra cac phan tu la so nguyen to trong mang\n");
		printf("7.Su dung thuat toan sap xep noi bot cac phan tu tren duong cheo chinh cua mang giam dan\n");
		printf("8.Nhap gia tri mang 1 chieu gom m phan tu va chi so dong muon chen vao mang, thuc hien chen vao mang 2 chieu\n");
		printf("Lua chon cua ban la: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
	            
	            //khai bao va nhap mang 2 chieu cap n*m
	            
	            for(int i=0;i<n;i++){
	        	    for(int j=0;j<m;j++){
		    	    printf("Nhap arr[%d][%d]= ",i,j);
			        scanf("%d",&arr[i][j]);
		            }
             	}
             	break;
	        case 2:
	        	for(int i=0;i<n;i++){
	        		for(int j=0;j<m;j++){
	        			printf("%d\t",arr[i][j]);
					}
					printf("\n");
				}
				break;
			case 3:
				cnt=0;
				for(int i=0;i<n;i++){
					for(int j=0;j<m;j++){
						if(arr[i][j]%2==0&&arr[i][j]%3==0){
							cnt++;
						}
					}
				}
				printf("%d",cnt);
				break;
			case 4:
				
				break;
			case 5:
				for(int j=0;j<m;j++){
					for(int i=0;i<n;i++){
						int min_pos=i;
						for(int k=i+1;k<n;k++){
							if(arr[k][j]<arr[min_pos][j]){
								min_pos=k;
							}
						}
						int temp=arr[i][j];
						arr[i][j]=arr[min_pos][j];
						arr[min_pos][j]=temp;
					}
				}
				for(int i=0;i<n;i++){
	        		for(int j=0;j<m;j++){
	        			printf("%d\t",arr[i][j]);
					}
					printf("\n");
				}
				break; 
			case 7:
				if(m!=n){
					printf("Khong co duong cheo chinh");
				} else{
					for(int i=0;i<m;i++){
						for(int j=0;j<m-i-1;j++){
							if(arr[j][j]<arr[j+1][j+1]){
								int temp=arr[j][j];
								arr[j][j]=arr[j+1][j+1];
								arr[j+1][j+1]=temp;
							}
						}
					}
				}
				for(int i=0;i<n;i++){
	        		for(int j=0;j<m;j++){
	        			printf("%d\t",arr[i][j]);
					}
					printf("\n");
				}
				break;
			case 8:
				for(int i=0;i<m;i++){
					printf("a[%d]=",i);
					scanf("%d",&a[i]);
				}
				printf("Nhap chi so hang muon chen:");
				scanf("%d",&row);
				if(row>=n){
					int new_arr[row+1][m];
					for(int i=0;i<row+1;i++){
						for(int j=0;j<m;j++){
							if(i<n){
								new_arr[i][j]=arr[i][j];
							} else if(i<row){
								new_arr[i][j]=0;
							} else {
								new_arr[row][j]=a[j];
							}
						}
					
					}
				}else{
					int new_arr[n+1][m];
					for(int i=0;i<n+1;i++){
						for(int j=0;j<m;j++){
							if(i<row){
								new_arr[i][j]=arr[i][j];
							}else if(i==row){
								new_arr[row][j]=a[j];
							}else{
								new_arr[i][j]=arr[i-1][j];
							}							
						}
					}
				}
			    break;
			case 9:
			    exit(0);
			default:
			    printf("Lua chon tu 1 den 9");			    
	    }
	}while(1==1);

}
