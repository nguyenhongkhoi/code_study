#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Kích thước của mảng và stack phải đủ lớn cho chuỗi đầu vào
#define MAX_LEN 21

// Khai báo stack và top là biến toàn cục
// Lưu ý: Dùng char stack sẽ tiện hơn, nhưng ta sẽ giữ lại int arr để giống code gốc của bạn
int arr[MAX_LEN];
int top = -1;

// Các hàm thao tác với stack (giữ nguyên)
void push(int x)
{
    top++;
    arr[top] = x;
}

void pop()
{
    if (top != -1)
    {
        top--;
    }
}

// Hàm remove đã được sửa lại hoàn toàn
void findLargestNumber(char *s, int k)
{
    int n = strlen(s);
    top = -1; // Luôn reset stack trước khi sử dụng

    // 1. Duyệt qua từng ký tự của chuỗi
    for (int i = 0; i < n; i++)
    {
        int currentDigit = s[i] - '0';

        // 2. Dọn dẹp stack: Dùng vòng lặp while với 3 điều kiện
        while (top != -1 && arr[top] < currentDigit && k > 0)
        {
            pop();
            k--;
        }

        // 3. Push chữ số hiện tại vào stack
        push(currentDigit);
    }

    // 4. Xử lý trường hợp vẫn còn lượt xóa k > 0 (ví dụ: s = "12345")
    while (k > 0 && top != -1)
    {
        pop();
        k--;
    }

    // Hàm này chỉ xây dựng stack, việc in sẽ do hàm main đảm nhận
}

int main()
{
    int k;
    char num[MAX_LEN];
    scanf("%s %d", num, &k);

    // Gọi hàm để xây dựng stack kết quả
    findLargestNumber(num, k);

    // In kết quả từ các phần tử còn lại trong stack
    if (top == -1)
    {
        printf("EMPTY\n"); // Hoặc không in gì cả tùy yêu cầu đề bài
    }
    else
    {
        for (int i = 0; i <= top; i++)
        {
            printf("%d", arr[i]);
        }
        printf("\n");
    }

    return 0;
}