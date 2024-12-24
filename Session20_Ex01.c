#include <stdio.h>
#include <string.h>

struct thuVien{
    int id;
    char tenSach[100];
    char tacGia[100];
    char theLoai[100];
    float giaTien;
};
typedef struct thuVien thuVien;
thuVien sach[100];
void nhapThongTinSach(thuVien sach[], int soLuongSach){
    for(int i = 0; i < soLuongSach; i++){
        sach[i].id = i + 1;
        fflush(stdin);
        printf("nhap ten sach id %d la: ", i + 1);
        fgets(sach[i].tenSach, sizeof(sach[i].tenSach), stdin);
        sach[i].tenSach[strlen(sach[i].tenSach) - 1] = '\0';
        printf("nhap ten tac gia id %d la: ", i + 1);
        fgets(sach[i].tacGia, sizeof(sach[i].tacGia), stdin);
        sach[i].tacGia[strlen(sach[i].tacGia) - 1] = '\0';
        printf("nhap the loai sach id %d la: ", i + 1);
        fgets(sach[i].theLoai, sizeof(sach[i].theLoai), stdin);
        sach[i].theLoai[strlen(sach[i].theLoai) - 1] = '\0';
        fflush(stdin);
        printf("nhap gia tien: ");
        scanf("%f", &sach[i].giaTien);
    }
}
void hienThongTinSach(thuVien sach[], int soLuongSach){
    for(int i = 0; i < soLuongSach; i++){
    printf("id: %d | ten sach: %s | tac gia: %s | the loai: %s | gia tien %.2f\n", sach[i].id, sach[i].tenSach, sach[i].tacGia, sach[i].theLoai, sach[i].giaTien);
    }  
}
void themSach(thuVien sach[], int *soLuongSach){
    int viTriThem;
    printf("vi tri them sach: ");
    scanf("%d", &viTriThem);
    if (viTriThem < 0 || viTriThem > *soLuongSach) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    for(int i = *soLuongSach; i > viTriThem; i--){
        sach[i] = sach[i - 1];
    }
    (*soLuongSach)++;
    sach[viTriThem].id = (*soLuongSach);
    printf("nhap ten sach vua them la: ");
    fflush(stdin);
    fgets(sach[viTriThem].tenSach, sizeof(sach[viTriThem].tenSach), stdin);
    sach[viTriThem].tenSach[strlen(sach[viTriThem].tenSach) - 1] = '\0';
    printf("nhap ten tac gia sach vua them la: ");
    fgets(sach[viTriThem].tacGia, sizeof(sach[viTriThem].tacGia), stdin);
    sach[viTriThem].tacGia[strlen(sach[viTriThem].tacGia) - 1] = '\0';
    printf("nhap the loai sach vua them la: ");
    fgets(sach[viTriThem].theLoai, sizeof(sach[viTriThem].theLoai), stdin);
    sach[viTriThem].theLoai[strlen(sach[viTriThem].theLoai) - 1] = '\0';
    fflush(stdin);
    printf("nhap gia tien sach vua them: ");
    scanf("%f", &sach[viTriThem].giaTien);
    printf("da them sach");
}
void xoaSach(thuVien sach[], int *soLuongSach){
    int viTriXoa;
    int idXoa = 0;
    printf("nhap id sach can xoa: ");
    scanf("%d", &viTriXoa);
    for(int i = 0; i < *(soLuongSach); i++){
        if(viTriXoa == sach[i].id){
            idXoa = i;
            break;
        }
    }
    if(idXoa == 0){
        printf("khong tim thay id de xoa sach");
        return;
    }
    for(int i = idXoa; i < *soLuongSach; i++){
        sach[i] = sach [i + 1];
    }
    (*soLuongSach)--;
    printf("da xoa sach khoi thu vien");
}
void capNhatSach(thuVien sach[], int soLuongSach){
    int idCapNhat;
    int vtriCapNhat = 0;
    printf("nhap id sach can cap nhat: ");
    scanf("%d", &idCapNhat);
    for(int i = 0; i < soLuongSach; i++){
        if(idCapNhat == sach[i].id){
            vtriCapNhat = i;
            break;
        }
    }
    if(vtriCapNhat == 0){
        printf("khong tim thay id de xoa sach");
        return;
    }
    fflush(stdin);
    printf("nhap ten sach cap nhat la: ");
    fgets(sach[vtriCapNhat].tenSach, sizeof(sach[vtriCapNhat].tenSach), stdin);
    sach[vtriCapNhat].tenSach[strlen(sach[vtriCapNhat].tenSach) - 1] = '\0';
    printf("nhap ten tac gia cap nhat la: ");
    fgets(sach[vtriCapNhat].tacGia, sizeof(sach[vtriCapNhat].tacGia), stdin);
    sach[vtriCapNhat].tacGia[strlen(sach[vtriCapNhat].tacGia) - 1] = '\0';
    printf("nhap the loai sach cap nhat la: ");
    fgets(sach[vtriCapNhat].theLoai, sizeof(sach[vtriCapNhat].theLoai), stdin);
    sach[vtriCapNhat].theLoai[strlen(sach[vtriCapNhat].theLoai) - 1] = '\0';
    fflush(stdin);
    printf("nhap gia tien sach cap nhat: ");
    scanf("%f", &sach[vtriCapNhat].giaTien);
    printf("da cap nhat sach");
}
void sapXepSach(thuVien sach[], int soLuongSach){
    for(int i = 0; i < soLuongSach - 1; i++){
        for(int j = 0; j < soLuongSach - 1 - i; i++){
            if(sach[j].giaTien > sach[j + 1].giaTien){
                struct thuVien temp = sach[j];
                sach[j] = sach[j + 1];
                sach[j + 1] = temp;
            }
        }
    }
    printf("da sap xep sach");
}
void timKiemSach(thuVien sach[], int soLuongSach){
    char tenSachTimKiem[100];
    int checkTimKiem = 0;
    printf("nhap ten sach can tim kiem: ");
    fflush(stdin);
    fgets(tenSachTimKiem, sizeof(tenSachTimKiem), stdin);
    tenSachTimKiem[strlen(tenSachTimKiem) - 1] = '\0';
    fflush(stdin);
    for(int i = 0; i < soLuongSach; i++){
        if(strcmp(sach[i].tenSach, tenSachTimKiem) == 0){
            printf("ten sach tim kiem co o id %d", i + 1);
            checkTimKiem = 1;
        }
    }
    if(!checkTimKiem){
        printf("khong tim thay ten sach tren");
    }
}
int main(){
    int soLuongSach;
    int check = 0;
    int luaChon;
    while(1){
        printf("\n==========MENU==========\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Hien thi thong tin sach\n");
        printf("3. Them sach vao vi tri\n");
        printf("4. Xoa sach theo ma sach\n");
        printf("5. Cap nhat thong tin sach theo ma sach\n");
        printf("6. Sap xep sach theo gia\n");
        printf("7. Tim kiem sach theo ten sach\n");
        printf("8. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &luaChon);
        switch(luaChon){
            case 1: //Nhap so luong va thong tin sach
                check = 1;
                printf("nhap so luong sach trong thu vien: ");
                scanf("%d", &soLuongSach);
                if (soLuongSach <= 0){
                    printf("so luong sach khong hop le");
                    break;
                } else if (soLuongSach > 100){
                    printf("so luong sach qua nhieu");
                    break;
                }
                nhapThongTinSach(sach, soLuongSach);
                break;
            case 2: //Hien thi thong tin sach
                if (check == 0){
                    printf("chua nhap thong tin sach");
                    break;
                }
                hienThongTinSach(sach, soLuongSach);
                break;
            case 3: //Them sach vao vi tri
                if (check == 0){
                    printf("chua nhap thong tin sach");
                    break;
                }
                themSach(sach, &soLuongSach);
                break;
            case 4: //Xoa sach theo ma sach
                if (check == 0){
                    printf("chua nhap thong tin sach");
                    break;
                }
                xoaSach(sach, &soLuongSach);
                break;
            case 5: //Cap nhat thong tin sach theo ma sach
                if (check == 0){
                    printf("chua nhap thong tin sach");
                    break;
                }
                capNhatSach(sach, soLuongSach);
                break;
            case 6: //Sap xep sach theo gia
                if (check == 0){
                    printf("chua nhap thong tin sach");
                    break;
                }
                sapXepSach(sach, soLuongSach);
                break;
            case 7: //Tim kiem sach theo ten sach
                if (check == 0){
                    printf("chua nhap thong tin sach");
                    break;
                }
                timKiemSach(sach, soLuongSach);
                break;
            case 8: //Thoat
                return 0;
            default:
                printf("nhap lua chon khong hop le");
        }
    }
}