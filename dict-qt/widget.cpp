#include "widget.h"
#include "ui_widget.h"
#include <QTextCodec>


#define MAX 111111 //最大记录数

struct dict
{
    char *key;
    char *content;
};


void format_string(char *str)//去掉字符串结尾的回车，空格字符
{
    ssize_t i;
    for(i = ssize_t(strlen(str) - 1); i >= 0; i--)
    {
        if (str[i] != '\n' && str[i] != ' ' && str[i] != '\r')
        {
            str[i + 1] = '\0';
            break;
        }
    }
}

//打开字典文件，并读取文件内容
int open_dict(struct dict **p, const char *dict_filename)
{
    FILE *pfile = fopen(dict_filename, "r");
    if (pfile == NULL)
        return 0;//打开文件失败，函数返回

    *p = (struct dict *)malloc(sizeof(struct dict) * MAX);//固定分配MAX大小内存
    memset(*p, 0, sizeof(struct dict) * MAX);//将分配内存初始化为0

    char buf[1024] = { 0 };
    size_t len = 0;
    int i = 0;//计数器
    while (!feof(pfile))//循环读取文件，直到文件末尾
    {
        memset(buf, 0, sizeof(buf));
        fgets(buf, sizeof(buf), pfile);//读取文件一行
        len = strlen(buf);//得到读取到字符串长度
        if (len > 0)
        {
            (*p)[i].key = (char *)malloc(len);//根据字符串长度分配内存
            memset((*p)[i].key, 0, len);
            format_string(buf);//去掉字符串结尾的空格和回车
            strcpy((*p)[i].key, &buf[1]);//将读取到的内容拷贝到key中
        }

        memset(buf, 0, sizeof(buf));
        fgets(buf, sizeof(buf), pfile);
        len = strlen(buf);
        if (len > 0)
        {
            (*p)[i].content = (char *)malloc(len);
            memset((*p)[i].content, 0, len);
            strcpy((*p)[i].content, &buf[6]);
        }

        i++;//计数器加1
    }
    fclose(pfile);//关闭字典文件

    return i;//返回读取到的字典词条数
}

//根据关键字key,在字典中查找内容
int search_dict(const struct dict *p, int size, const char *key, char *content)
{
    int i = 0;
    for (i = 0; i < size; i++)//遍历字典
    {
        if ((p[i].key == NULL) || (p[i].content == NULL))
            continue;

        if (strcmp(p[i].key, key) == 0)
        {
            strcpy(content, p[i].content);
            return 1;//找到符合条件记录，返回1
        }
    }
    return 0;//没有找到符合条件记录，返回0
}

//释放内存
void free_dict(struct dict *p, int size)
{
    int i = 0;
    for (i = 0; i < size; i++)//循环释放key与content成员内存
    {
        if (p[i].key)
            free(p[i].key);
        if (p[i].content)
            free(p[i].content);
    }
    free(p);//释放p内存
}

struct dict *p = NULL;
int dict_size = 0;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    dict_size = open_dict(&p, "./dict.txt");//根据命令行第一个参数做为字典文件名，打开字典文件
    if (dict_size == 0)
            exit(0);//打开字典文件失败，程序退出
    ui->setupUi(this);
}

Widget::~Widget()
{
    free_dict(p, dict_size);
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QTextCodec *codec = QTextCodec::codecForName("GBK");//建立一个从UTF8到GBK转化的桥梁
    char key[1024] = { 0 };
    char content[1024] = { 0 };
    //ui->lineEdit->text();//得到用户在edit中输入的内容，类型是QString，QString是QT提供的一个字符串类
    //qt默认的字符串都是UTF8编码的
    strcpy(key, codec->fromUnicode(ui->lineEdit->text()));//结果就是把用户在edit输入的字符修改成GBK编码
    format_string(key);
    if (search_dict(p, dict_size, key, content))//根据用户输入，在字典中检索
    {
        //content内容是GBK格式的字符串
        ui->label->setText(codec->toUnicode(content));//把GBK编码转化为UTF8格式
         //printf("%s", content);
    } else
    {
        ui->label->setText("not found");
    }
}
