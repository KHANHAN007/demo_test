#include <stdio.h>

int main() {
	int a[100][100];
	while(1) {
		printf("\n\tMENU\n");
		printf("\n1. Nhap kich co va gia tri cac phan tu cua mang.\n");
		printf("2. In gia tri cac phan tu cua mang theo ma tran.\n");
		printf("3. In ra cac phan tu nam tren duong bien va tinh tich.\n");
		printf("4. In ra cac phan tu nam tren duong cheo chinh.\n");
		printf("5. In ra cac phan tu nam tren duong cheo phu.\n");
		printf("6. Sap xep duong cheo chinh theo thu tu tang dan.\n");
		printf("7. Tim kiem mot phan tu va in ra vi tri cua phan tu do trong mang.\n");
		printf("8. Thoat\n");
		printf("Nhap lua chon: ");
		int option;
		scanf("%d", &option);
		int row,col, result, minSize, tmp[100], temp,value=0,idx[100],count,found;
		switch (option) {
			case 1:
				printf("Nhap so hang: ");
				scanf("%d", &row);
				printf("Nhap so cot: ");
				scanf("%d", &col);

				for(int i=0; i<row; ++i) {
					for(int j=0; j<col; ++j) {
						printf("Nhap phan tu thu a[%d][%d]", i,j);
						scanf("%d",&a[i][j]);
					}
				}
				break;
			case 2:
				for(int i=0; i<row; ++i) {
					for(int j=0; j<col; ++j) {
						printf("%d ", a[i][j]);
					}
					printf("\n");
				}
				break;
			case 3:
				result=1;
				for(int i=0; i<row; ++i) {
					for(int j=0; j<col; ++j) {
						if(i==0||i==row-1||j==0||j==col-1) {
							printf("%d ", a[i][j]);
							result*=a[i][j];
						}
					}
				}
				printf("\nTich cua cac phan tu tren duong bien la: %d\n", result);
				break;
			case 4:
				if(row==col) {
					printf("Cac phan tu nam tren duong cheo chinh: ");
					for(int i=0; i<row; ++i)
						printf("%d ",a[i][i]);
				} else
					printf("Mang khong phai ma tran vuong.\n");
				break;
			case 5:
				if(row==col) {
					printf("Cac phan tu nam tren duong cheo phu: ");
					for(int i=col-1; i>=0; --i)
						printf("%d ",a[i][col-i-1]);
				} else
					printf("Mang khong phai ma tran vuong.\n");
				break;
			case 6:
				if(row==col) {
					for(int i=0; i<row; ++i) {
						tmp[i]=a[i][i];
					}

					for(int i=row-1; i>=0; --i) {
						for(int j=0; j<i; ++j) {
							if(tmp[j]>tmp[j+1]) {
								temp=tmp[j];
								tmp[j]=tmp[j+1];
								tmp[j+1]=temp;
							}
						}
					}

					for(int i=0; i<row; ++i) {
						a[i][i]=tmp[i];
					}
				} else
					printf("Mang khong phai ma tran vuong.\n");
				break;
			case 7:
				printf("Nhap mot so de kiem tra: ");
				scanf("%d", &value);

				found = -1;
				count = 0;

				printf("So %d xuat hien trong mang o vi tri: ", value);
				for (int i = 0; i < row; ++i) {
					for (int j = 0; j < col; ++j) {
						if (a[i][j] == value) {
							printf("(%d, %d) ", i+1, j+1);
							found = 1;
							++count;
						}
					}
				}

				if (found == -1) {
					printf("\nKhong tim thay gia tri %d trong mang.\n", value);
				} else {
					printf("\nTong so lan xuat hien: %d\n", count);
				}
				break;

			case 8:
				printf("Hen gap lai.");
				return 0;
			default:
				printf("Lua chon khong hop le. Vui long nhap lai.");
				break;
		}
	}
}
