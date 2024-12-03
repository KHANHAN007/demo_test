#include <stdio.h>
int currentLenght;

int main()
{
    int arr[101] = {0};

    while (1)
    {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu can nhap va gia tri cac phan tu.\n");
        printf("2. In ra gia tri cac phan tu dang quan ly.\n");
        printf("3. In ra gia tri lon nhat.\n");
        printf("4. In ra cac phan tu la so nguyen to trong mang.\n");
        printf("5. Them mot phan tu vao vi tri chi dinh.\n");
        printf("6. Xoa mot phan tu trong mang.\n");
        printf("7. Sap xep mang theo thu tu tang dan.\n");
        printf("8. Tim kiem phan tu va in ra vi tri index cua phan tu do.\n");
        printf("9. Thoat.");
        int option, idx, num, max,count,tmp;
        printf("\nNhap lua chon: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            int n;
            printf("So phan tu can nhap: ");
            scanf("%d", &n);
            currentLenght = n;
            for (int i = 0; i < n; ++i)
            {
                printf("Nhap phan tu thu %d: ", i + 1);
                scanf("%d", arr + i);
            }
            break;
        case 2:
            for (int i = 0; i < currentLenght; ++i)
                printf("%d ", *(arr + i));
            printf("\n");
            break;
        case 3:
            max = arr[0];
            for (int i = 0; i < currentLenght; ++i)
            {
                if (arr[i] > max)
                    max = arr[i];
            }
            printf("Phan tu lon nhat: %d\n", max);
            break;
        case 4:
            printf("Cac phan tu la so nguyen to: ");
            for (int i = 0; i < currentLenght; ++i)
            {
                int prime = 0;
                for (int j = 2; j * j <= arr[i]; ++j)
                {
                    if (arr[i] % j == 0)
                        prime = 1;
                }
                if (!prime && arr[i] > 1)
                {
                    printf("%d ", arr[i]);
                }
            }
            break;
        case 5:
            idx, num;
            printf("Vi tri can them: ");
            scanf("%d", &idx);
            printf("Gia tri them: ");
            scanf("%d", &num);
            if (idx > currentLenght)
            {
                arr[idx - 1] = num;
            }
            else
            {
                for (int i = currentLenght; i >= idx; --i)
                {
                    arr[i] = arr[i - 1];
                }
                arr[idx - 1] = num;
                ++currentLenght;
            }
            break;
        case 6:
            printf("Vi tri can xoa: ");
            scanf("%d", &idx);
            for (int i = idx - 1; i < currentLenght - 1; ++i)
            {
                arr[i] = arr[i + 1];
            }
            --currentLenght;
            break;
        case 7:
		    for (int i = currentLenght - 1; i > 0; --i)
		    {
		        for (int j = 0; j < i; ++j)
		        {
		        	if(arr[j]>arr[j+1])
		            {
						tmp = arr[j];
			            arr[j] = arr[j + 1];
			            arr[j + 1] = tmp;
			        }
		        }
		    }
			break;
		case 8:
		    count = 0;
		    printf("Nhap mot so de kiem tra: ");
		    scanf("%d", &num);
		
		    for (int i = 0; i < currentLenght; ++i)
		    {
		        if (num == arr[i])
		        {
		            count++;
		            printf("So %d xuat hien tai vi tri index: %d\n", num, i); // In t?ng v? trí (index)
		        }
		    }
		
		    if (count > 0)
		        printf("\nSo lan xuat hien cua so %d trong mang: %d\n", num, count);
		    else
		        printf("\nKhong tim thay so %d trong mang.\n", num);
		    break;
        case 9: // Thoat
            printf(":))");
            return 0;
        default: // lua chon khong hop le
            printf("Lua chon khong hop le.");
            break;
        }
    }
    return 0;
}
