#include "bank.h"

void displayMainMenu() {
    printf("\n=========================================\n");
    printf("   🏦 نظام إدارة خدمات البنك الإلكتروني   \n");
    printf("=========================================\n");
    printf("1.. قسم التسجيل وتفعيل البطاقات\n");
    printf("2.  قسم العمليات المالية (خدمة العميل)\n");
    printf("3.  قسم الاستعلام والبحث\n");
    printf("4.  التراجع عن آخر عملية (Undo)\n");
    printf("0.  الخروج من النظام\n");
    printf("=========================================\n");
    printf("اختر الرقم المطلوب: ");
}

int main() {
    Queue q;
    Stack s;

    
    init_queue(&q);
    init_stack(&s);

    int choice;
    int idCounter = 101; // ترقيم تلقائي للعملاء

    do {
        displayMainMenu();
        if (scanf("%d", &choice) != 1) {
            printf("إدخال غير صحيح! ❌\n");
            while(getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1: { // إضافة عميل جديد للطابور 🎟️
                char name[50], problem[100];
                printf("\n---  قسم التسجيل وتفعيل البطاقات ---\n");
                printf("أدخل اسم العميل: ");
                scanf(" %[^\n]", name);
                printf("أدخل نوع الخدمة / المشكلة: ");
                scanf(" %[^\n]", problem);

                Node *newCustomer = createNode(idCounter++, name, problem);
                if (newCustomer != NULL) {
                    enqueue(&q, newCustomer);
                    printf("✅ تم إضافة العميل [%s] بنجاح! رقم العميل: %d\n", name, newCustomer->id);
                }
                break;
            }
            case 2: { // خدمة العميل التالي 
                printf("\n---  قسم العمليات المالية ---\n");
                Node *served = dequeue(&q);
                if (served == NULL) {
                    printf("⚠️ لا يوجد عملاء في الطابور حالياً!\n");
                } else {
                    printf("جاري خدمة العميل رقم [%d]: %s (الخدمة: %s)...\n", served->id, served->name, served->problem);
                    
                    // زر تأكيد إتمام العملية 
                    int confirm;
                    printf("هل تم إتمام الخدمة بنجاح؟ (1. نعم / 0. إلغاء): ");
                    scanf("%d", &confirm);

                    if (confirm == 1) {
                        push(&s, served);
                        printf("✅ تم إتمام الخدمة وحفظ العملية في المكدس للتراجع.\n");
                    } else {
                        enqueue_at_front(&q, served);
                        printf("🔄 تم إلغاء العملية وإعادة العميل لمقدمة الطابور.\n");
                    }
                }
                break;
            }
            case 3: { // استعلام سريع 
                printf("\n--- 🔍 قسم الاستعلام والبحث ---\n");
                if (q.front == NULL) {
                    printf("الطابور فارغ حالياً.\n");
                } else {
                    printf("العميل الحالي في مقدمة الطابور: %s (رقم %d)\n", q.front->name, q.front->id);
                }
                break;
            }
            case 4: { // عملية التراجع 
                printf("\n--- 🔄 التراجع عن آخر عملية (Undo) ---\n");
                Node *lastServed = pop(&s);
                if (lastServed == NULL) {
                    printf("⚠️ لا توجد عمليات مكتملة للتراجع عنها!\n");
                } else {
                    enqueue_at_front(&q, lastServed);
                    printf("✅ تم التراجع عن خدمة العميل [%s] وإعادته لخدمة العملاء في الطابور!\n", lastServed->name);
                }
                break;
            }
            case 0:
                printf("\n🚪 جاري الخروج من النظام... شكرًا لاستخدامك التطبيق!\n");
                break;
            default:
                printf("❌ اختيار غير صحيح، حاول مرة أخرى.\n");
        }

    } while (choice != 0);

    return 0;
}
