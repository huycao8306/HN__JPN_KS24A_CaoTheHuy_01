#include <stdio.h>

int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void bubbleSortDesc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSortAsc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int arr[100];
    int luachon;
    int sophantu = 0;
    do {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va gia tri cho mang\n");
        printf("2. In ra gia tri cac phan tu trong mang\n");
        printf("3. Tim gia tri nho nhat va lon nhat trong mang\n");
        printf("4. In ra tong cua tat ca phan tu\n");
        printf("5. Them vao mot phan tu vao cuoi mang\n");
        printf("6. Xoa phan tu tai mot vi tri cu the (nguoi dung nhap vi tri)\n");
        printf("7. Sap xep mang theo thu tu giam dan (Bubble sort)\n");
        printf("8. Nhap vao 1 phan tu va tim kiem xem no co trong mang hay khong (Linear search)\n");
        printf("9. In ra toan bo so nguyen to trong mang\n");
        printf("10. Sap xep mang theo thu tu tang dan (Selection sort)\n");
        printf("11. Thoat\n");
        printf("Moi ban nhap vao lua chon cua minh: ");
        scanf("%d", &luachon);
        switch (luachon) {
            case 1:
                printf("Nhap vao so phan tu cua mang: ");
                scanf("%d", &sophantu);
                for (int i = 0; i < sophantu; i++) {
                    printf("arr[%d] = ", i);
                    scanf("%d", &arr[i]);
                }
                break;
            case 2:
                printf("Gia tri cac phan tu trong mang la: ");
                for (int i = 0; i < sophantu; i++) {
                    printf("%d ", arr[i]);
                }
                break;
            case 3:
                if (sophantu > 0) {
                    int max = arr[0];
                    int min = arr[0];
                    for (int i = 1; i < sophantu; i++) {
                        if (arr[i] > max) {
                            max = arr[i];
                        }
                        if (arr[i] < min) {
                            min = arr[i];
                        }
                    }
                    printf("Phan tu lon nhat cua mang la: %d\n", max);
                    printf("Phan tu nho nhat cua mang la: %d\n", min);
                }
                break;
            case 4:
                if (sophantu > 0) {
                    int sum = 0;
                    for (int i = 0; i < sophantu; i++) {
                        sum += arr[i];
                    }
                    printf("Tong cua tat ca cac phan tu la: %d\n", sum);
                }
                break;
            case 5:
                if (sophantu < 100) {
                    int phanTu;
                    printf("Nhap phan tu can them: ");
                    scanf("%d", &phanTu);
                    arr[sophantu] = phanTu;
                    sophantu++;
                    printf("Mang sau khi them phan tu: ");
                    for (int i = 0; i < sophantu; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                } else {
                    printf("Khong the them phan tu, mang da day.\n");
                }
                break;
            case 6:
                if (sophantu > 0) {
                    int pos;
                    printf("Nhap vi tri muon xoa (0 den %d): ", sophantu - 1);
                    scanf("%d", &pos);
                    if (pos >= 0 && pos < sophantu) {
                        for (int i = pos; i < sophantu - 1; i++) {
                            arr[i] = arr[i + 1];
                        }
                        sophantu--;
                        printf("Mang sau khi xoa phan tu: ");
                        for (int i = 0; i < sophantu; i++) {
                            printf("%d ", arr[i]);
                        }
                        printf("\n");
                    } else {
                        printf("Vi tri khong hop le.\n");
                    }
                } else {
                    printf("Mang rong, khong co gi de xoa.\n");
                }
                break;
            case 7:
                bubbleSortDesc(arr, sophantu);
                printf("Mang sau khi sap xep giam dan: ");
                for (int i = 0; i < sophantu; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 8:
                if (sophantu > 0) {
                    int x;
                    printf("Nhap phan tu can tim: ");
                    scanf("%d", &x);
                    if (linearSearch(arr, sophantu, x)) {
                        printf("Phan tu %d co ton tai trong mang.\n", x);
                    } else {
                        printf("Phan tu %d khong ton tai trong mang.\n", x);
                    }
                } else {
                    printf("Mang rong.\n");
                }
                break;
            case 9:
                if (sophantu > 0) {
                    int foundPrime = 0;
                    printf("Cac so nguyen to trong mang: ");
                    for (int i = 0; i < sophantu; i++) {
                        if (isPrime(arr[i])) {
                            printf("%d ", arr[i]);
                            foundPrime = 1;
                        }
                    }
                    if (!foundPrime) {
                        printf("Khong co so nguyen to nao trong mang");
                    }
                    printf("\n");
                } else {
                    printf("Mang rong.\n");
                }
                break;
            case 10:
                selectionSortAsc(arr, sophantu);
                printf("Mang sau khi sap xep tang dan: ");
                for (int i = 0; i < sophantu; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 11:
                printf("Ket thuc chuong trinh!\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (luachon != 11);
    return 0;
}

