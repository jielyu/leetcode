#include <stdio.h>
#include <stdlib.h>

// ListNode
typedef struct sListNode ListNode;
struct sListNode
{
    int id;
    int time_stamp;
    struct sListNode * next;
};

typedef struct {
    ListNode * head;
}LogSystem;

// 日志初始化
LogSystem* LogSystemInit(){
    LogSystem * p_lsys = (LogSystem*)malloc(sizeof(LogSystem));
    p_lsys->head = NULL; 
    return p_lsys;
}

// 插入一个给定的ID和timestamp的日志
// maintain an ascending list in timeStamp
void LogSystemAdd(LogSystem *obj, int id, int timeStamp){
    // create a ListNode
    ListNode * p_node = (ListNode*)malloc(sizeof(ListNode));
    p_node->id = id;
    p_node->time_stamp = timeStamp;
    p_node->next = NULL;
    // insert into LogSystem
    // for empty LogSystem
    if (NULL == obj->head) {
        obj->head = p_node;
        return;
    }
    // for timeStamp smaller than all history log
    ListNode * head = obj->head;
    if (p_node->time_stamp <= head->time_stamp) {
        p_node->next = head;
        obj->head = p_node;
        return;
    }
    // for general insert
    ListNode * next = NULL;
    while(head) {
        next = head->next;
        if (NULL == next) {
            head->next = p_node;
            return;
        }
        if (next->time_stamp >= p_node->time_stamp) {
            head->next = p_node;
            p_node->next = next;
            return;
        }
        head = next;
    }
}

// 查询时间戳在区间[startTime, endTime]内 日志的数量，若没有则返回0
int LogSystemQuery(LogSystem *obj, int startTime, int endTime) {
    ListNode * head = obj->head;
    int ret = 0;
    // query in ascending order list
    while(head) {
        if (head->time_stamp > endTime) {break;}
        if (head->time_stamp >= startTime) {++ret;}
        head = head->next;
    }
    return ret;
}

// 删除制定ID的日志，若找到日志并删除则返回0，若日志不存在则返回-1
int LogSystemDelete(LogSystem *obj, int id) {
    ListNode * head = obj->head;
    // check empty List
    if (NULL == head) {return -1;}
    // check the first Node
    if (head->id == id) {
        obj->head = head->next;
        free(head);
        return 0;
    }
    // check other nodes
    while(head->next) {
        if (head->next->id == id) {
            ListNode * p = head->next;
            head->next = p->next;
            free(p);
            return 0;
        }
        head = head->next;
    }
    // not exist such node
    return -1;
}

// 释放日志系统
void LogSystemFree(LogSystem *obj) {
    ListNode * head = obj->head;
    ListNode * next = head->next;
    // free all ListNode
    while (head) {
        next = head->next;
        free(head);
        head = next;
    }
    // free LogSystem
    free(obj);
    obj = NULL;
}

// print all node elements in List
void print(ListNode * head, char * info) {
    printf("%s:[", info);    
    while (head) {
        printf("Node(t=%d,id=%d),", head->time_stamp, head->id);
        head  = head->next;
    }
    printf("]\r\n");
}

int main() {
    int res;
    // initialize
    LogSystem *obj = LogSystemInit();
    print(obj->head, "init");
    // insert a node
    LogSystemAdd(obj, 1, 2); // 添加id为1 timeStamp为2的节点
    print(obj->head, "insert(1,2)");
    // insert a node
    LogSystemAdd(obj, 2, 4);  
    print(obj->head, "insert(2,4)");   
    // insert a node   
    LogSystemAdd(obj, 3, 5);
    print(obj->head, "insert(3,5)");
    // query
    res = LogSystemQuery(obj, 3, 5); // id 为2和3的日志满足，返回日志个数2
    print(obj->head, "query([3,5])");
    printf("res=%d\r\n", res);
    // delete a node
    res = LogSystemDelete(obj, 2);    // 删除id为2的日志，返回0
    print(obj->head, "delete(id=2)");
    printf("res=%d\r\n", res);
    // query
    res = LogSystemQuery(obj, 3, 5);  // id 为2的日志被删除，仅id为3的日志满足，返回日志个数1
    print(obj->head, "query([3,5])");
    printf("res=%d\r\n", res);
    // delete a node
    res = LogSystemDelete(obj, 2);    // 删除id为2的日志，不存在该日志，返回 -1
    print(obj->head, "deleteAll");
    // delete log system
    LogSystemFree(obj);
    printf("res=%d\r\n", res);
    printf("obj=%d\r\n", (int)obj);

    return 0;
}