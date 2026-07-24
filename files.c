#include "bank.h"


void saveCustomerToFile(int id, const char *name, const char *problem) {
    FILE *fp = fopen("customers.txt", "a"); // "a" للإضافة في نهاية الملف
    if (fp == NULL) {
        printf("❌ خطأ في فتح الملف للحفظ!\n");
        return;
    }
    fprintf(fp, "%d,%s,%s\n", id, name, problem);
    fclose(fp);
    printf("💾 تم حفظ العميل [%s] في الملف النصي بنجاح.\n", name);
}

//  🆔
void searchByIdInFile(int searchId) {
    FILE *fp = fopen("customers.txt", "r");
    if (fp == NULL) {
        printf(" لا يوجد ملف بيانات للبحث فيه حالياً!\n");
        return;
    }

    int id;
    char name[50], problem[100];
    int found = 0;

    while (fscanf(fp, "%d,%49[^,],%99[^\n]\n", &id, name, problem) != EOF) {
        if (id == searchId) {
            printf("\n🔍 **تم العثور على العميل:**\n");
            printf("🆔 الرقم التعريفي: %d\n👤 الاسم: %s\n الخدمة: %s\n", id, name, problem);
            found = 1;
            break;
        }
    }

    if (!found) printf("❌ لم يتم العثور على عميل بالرقم [%d].\n", searchId);
    fclose(fp);
}


void searchByNameInFile(const char *searchName) {
    FILE *fp = fopen("customers.txt", "r");
    if (fp == NULL) {
        printf(" لا يوجد ملف بيانات للبحث فيه حالياً!\n");
        return;
    }

    int id;
    char name[50], problem[100];
    int found = 0;

    while (fscanf(fp, "%d,%49[^,],%99[^\n]\n", &id, name, problem) != EOF) {
        if (strcmp(name, searchName) == 0) { // مقارنة النصين
            printf("\n🔍 **تم العثور على العميل:**\n");
            printf("🆔 الرقم التعريفي: %d\n👤 الاسم: %s\n📝 الخدمة: %s\n", id, name, problem);
            found = 1;
            break;
        }
    }

    if (!found) printf("❌ لم يتم العثور على عميل باسم [%s].\n", searchName);
    fclose(fp);
}
