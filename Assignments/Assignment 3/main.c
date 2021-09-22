#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct POINT // Typedef dat lai ten cua struct
{
    int row;      // tọa độ x của nút
    int col;   // tọa độ y của nút
    int value;    // giá trị 0 hoặc 1 của nút
    bool visited; // đánh dấu nút đã được đi qua
    struct POINT *prev;  // con trỏ trỏ đến nút liền trước đó trước khi đi đến nút này
} point_t;

#define MAX_ROW 9 
#define MAX_COLUMN 9

#define MAX MAX_ROW*MAX_COLUMN

point_t matrix[MAX_ROW][MAX_COLUMN];
    
point_t surroundingPnt[4];

//Setup Queue

typedef struct
{
    point_t data[MAX]; // lưu trữ các nút
    int front;         // chỉ số đầu của hàng đợi
    int rear;          // chỉ số cuối của hàng đợi
} Queue;

// Hàm 1: Khởi tạo hàng đợi
void initQueue(Queue *q)
{
    q->front = 0;
    q->rear = -1;
}

// Hàm 2: Kiểm tra xem hàng đợi có rỗng hay không? Hàng đợi rỗng là hàng đợi mà chỉ số của đầu của hàng đợi
// lớn hơn chỉ số cuối của hàng đợi

int isEmpty(Queue q)
{
    return (q.rear < q.front);
}

// Hàm 3: Kiểm tra xem hàng đợi đã đầy chưa? Hàng đợi được xem là đầy là khi chỉ số cuối của hàng đợi lớn hơn
// số lượng phần tử tối đa mà hàng đợi có thể chứa

int isFull(Queue q)
{

    if (q.rear == MAX - 1)
    {
        return 1;
    }

    else
        return 0;
}

// Hàm 4: Thêm phần tử vào cuối (rear) của hàng đợi.
void enQueue(Queue *q, point_t x)
{
    if (!isFull(*q))
    {
        if (q->rear == MAX - 1)
        {
            for (int i = q->front; i <= q->rear; i++)
            {
                q->data[i - q->front] = q->data[i];
            }
            q->rear = MAX - q->front;
            q->front = 0;
        }
        q->rear = q->rear + 1;
        q->data[q->rear] = x;
    }
}

//  Hàm 5: Lấy phần tử đầu (front) ra khỏi hàng đợi.
point_t deQueue(Queue *q)
{
    point_t d;
    if (!isEmpty(*q))
    {
        d = q->data[q->front];
        q->front = q->front + 1;
    }
    if (q->front > q->rear)
    {
        initQueue(q);
    };
    return d;
}

// Hàm kiểm tra toạ độ có hợp lệ hay không
bool checkCoordinate(int x, int y)
{
    bool ret = false;
    if ((0 <= x && x <= MAX_ROW) && (0 <= y && x < MAX_COLUMN))
    {
        ret = true;
    }
    return ret;
}

// Hàm tìm các điểm xung quanh
void findSurroundingPoint(int x, int y, int *count)
{
    int tempCnt = 0; // khởi tạo số biến đếm số lượng các nút có thể đi được quanh 1 vị trí
    // kiểm tra xem vị trí điểm bên phải có đến được ko?
    if ((checkCoordinate(x, y + 1) == true) && (matrix[x][y + 1].value == 1))
    {
        surroundingPnt[tempCnt] = matrix[x][y + 1];
        tempCnt++;
    }

    // kiểm tra xem vị trí điểm bên dưới có đến được ko?
    if ((checkCoordinate(x + 1, y) == true) && (matrix[x + 1][y].value == 1))
    {
        surroundingPnt[tempCnt] = matrix[x + 1][y];
        tempCnt++;
    }

    // kiểm tra xem vị trí điểm bên trái có đến được ko?

    if ((checkCoordinate(x, y - 1) == true) && (matrix[x][y - 1].value == 1))
    {
        surroundingPnt[tempCnt] = matrix[x][y - 1];
        tempCnt++;
    }

    // kiểm tra xem vị trí điểm bên trên có đến được ko?
    
    if ((checkCoordinate(x - 1, y) == true) && (matrix[x - 1][y].value == 1))
    {
        surroundingPnt[tempCnt] = matrix[x - 1][y]; // copy toa do vao surroudingpnt
        tempCnt++;
    }
    *count = tempCnt; // tempCnt dem so nut xung quanh hop le
}

// Tìm đường đi ngắn nhất
void findShortestPath(int x, int y)
{
    Queue *queue;
    queue = (Queue*)malloc(sizeof(queue)); // Cấp phát 1 vùng nhớ có kích thước là kích thước của queue
    initQueue(queue); // Khởi tạo quêu
    matrix[0][0].visited = true; 
    enQueue(queue, matrix[0][0]); // Đưa toạ độ 0 0 vào queue
    bool found = false;
    int count = 0;
    while ((isEmpty(*queue) == false) && (found == false)) // Nếu hàng đợi không rỗng và chưa tìm thấy đường đi
    {
        point_t p = deQueue(queue); // Lấy ra phần tử đầu tiên của queue
        findSurroundingPoint(p.row, p.col, &count); // để tìm các nút xung quanh của nút p vừa lấy ra khỏi hàng đợi;
        point_t pp[4]; 
        memcpy(pp, surroundingPnt, sizeof(surroundingPnt)); // Sao chép các điểm xung quanh vào pp.
        for (int i = 0; i < count; i++)
        {
            if (matrix[pp[i].row][pp[i].col].visited == false)
            {
                matrix[pp[i].row][pp[i].col].visited = true;
                matrix[pp[i].row][pp[i].col].prev = &matrix[p.row][p.col]; // Cập nhật địa chỉ của nút trước đó

                if (pp[i].row == x && pp[i].col == y) { // Tìm thấy đường đi
                    found = true; 
                    break;
                }
                else {
                    enQueue(queue, matrix[pp[i].row][pp[i].col]); // Đưa pp[i] vào queue
                }
            }
        }
    }
    
    if (found == true)
    {
        point_t *temp = &matrix[x][y]; // temp trỏ tới nút đích
        while (temp -> prev != NULL) 
        {
            printf("(%d, %d) ", temp -> row, temp -> col);
            temp = temp -> prev;
        }
        printf("(%d, %d) ", temp -> row, temp -> col);
    }
    else
    {
        printf("Khong co duong di tu diem O(0, 0) den A(%d, %d)", x, y);
    }
}

int main() {
    int x = 0, y = 0;

    // Khai bao ma tran.
							           //0, 1, 2, 3, 4, 5, 6, 7, 8
	int values[MAX_ROW][MAX_COLUMN] =  {{1, 0, 0, 0, 1, 0, 1, 1, 0},  	// 0 //
                         	            {1, 1, 0, 1, 1, 1, 0, 0, 1},  	// 1 //
		                                {0, 1, 0, 1, 1, 0, 1, 0, 1},  	// 2 //
					                    {0, 1, 1, 0, 0, 1, 0, 1, 1},  	// 3 //
					                    {0, 0, 1, 0, 1, 0, 1, 0, 0},  	// 4 //
					                    {1, 1, 1, 0, 0, 0, 0, 1, 1},  	// 5 //
					                    {1, 0, 1, 1, 1, 1, 1, 0, 0},  	// 6 //
					                    {1, 1, 1, 0, 0, 0, 1, 0, 1},  	// 7 //
					                    {0, 0, 0, 1, 1, 1, 1, 1, 0}}; 	// 8 //

    for (int i = 0; i < MAX_ROW; i++) { // Khởi tạo các giá trị cho matrix
        for (int j = 0; j < MAX_COLUMN; j++) {
            matrix[i][j].row = i;
            matrix[i][j].col = j;
            matrix[i][j].value = values[i][j];
            matrix[i][j].visited = false;
        }
    }

    do {
        printf("Xin vui long nhap toa do x:\n");
        scanf("%d", &x);   

        if (x < 0 || x >= MAX_ROW)
        printf("Toa do x khong hop le!\n");

    } while (x < 0 || x >= MAX_ROW);


    do {
        printf("Xin vui long nhap toa do y:\n");
        scanf("%d", &y);   

        if (y < 0 || y >= MAX_COLUMN)
        printf("Toa do Y khong hop le!\n");

    } while (y < 0 || y >= MAX_COLUMN);

    findShortestPath(x, y);
    
}
