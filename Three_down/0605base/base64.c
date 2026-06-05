// base64.c
#include <openssl/bio.h> //basic inout output,类似FILE
#include <openssl/buffer.h>
#include <openssl/evp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//传入一个字符串
char *encode(char *str)
{
    //带f的函数是过滤器函数
    BIO *b64= BIO_new(BIO_f_base64());
    //source为内存的bio
    BIO *bio=BIO_new(BIO_s_mem());
    //给bio添加过滤器b64
    bio=BIO_push(b64,bio);
    //编码不换行
    BIO_set_flags(bio,BIO_FLAGS_BASE64_NO_NL);

    //写入bio中的数据
    BIO_write(bio,str,strlen(str));
    //刷新bio
    BIO_flush(bio);

    //内存缓冲区
    BUF_MEM *buf;
    BIO_get_mem_ptr(bio,&buf);
    //动态分配的内存空间
    char *data=malloc(buf->length+1);
    //将buf->data中的数据复制到data中
    memcpy(data,buf->data,buf->length);
    data[buf->length]='\0';
    BIO_free_all(bio);
    return data;
}

char *decode(char *data,int *len)
{
    //过滤器
    BIO *b64= BIO_new(BIO_f_base64());

    int input_len=strlen(data);
    printf("input:%d\n",input_len);

    //base64要解码的数据写入BIO内存缓冲区
    BIO *bio=BIO_new_mem_buf(data,input_len);
    bio=BIO_push(b64,bio);
    BIO_set_flags(bio,BIO_FLAGS_BASE64_NO_NL);
    
    char *buf=malloc(input_len);
    *len=BIO_read(bio,buf,input_len);
    BIO_free_all(bio);
    return buf;
}

void encode_file(char *in_file,char *out_file)
{
    BIO *b64=BIO_new(BIO_f_base64());
    //读
    BIO *in=BIO_new_file(in_file,"rb");
    //写
    BIO *out=BIO_new_file(out_file,"w");
    //给out添加过滤器b64
    out=BIO_push(b64,out);
   
    char buf[1024*4];
    //有效读取的字节数
    int n;
    while((n=BIO_read(in,buf,sizeof(buf)))>0)
    {
        BIO_write(out,buf,n);
    }
    //刷新out
    BIO_flush(out);
    //关闭in和out
    BIO_free_all(in);
    BIO_free_all(out);
    printf("ok\n");

}

void decode_file(char *in_file,char *out_file)
{
    BIO *b64=BIO_new(BIO_f_base64());
    BIO *in=BIO_new_file(in_file,"r");
    BIO *out=BIO_new_file(out_file,"wb");
    //给in添加过滤器b64
    in=BIO_push(b64,in);

    char buf[1024*4];
    int n;
    while((n=BIO_read(in,buf,sizeof(buf)))>0)
    {
        BIO_write(out,buf,n);
    }
     //刷新out
    BIO_flush(out);
    //关闭in和out
    BIO_free_all(in);
    BIO_free_all(out);
    printf("ok\n");
}
int main(int argc, char const* argv[])
{
    // 文本编码与解码
    // char *str="hello world";
    // char *data=encode(str);
    // printf("%s\n",data);
    //aGVsbG8gd29ybGQ=
    // free(data);

    // char *data="aGVsbG8gd29ybGQ=";
    // int len=0;
    // char *text=decode(data,&len);
    // printf("%s\n",text);
    // free(text);
    // free(data);


    // 文件编码与解码
    //可以编码图片文件
    encode_file("tux.jpg","tux.txt");
    //图片后缀有png,jpg,jpeg,gif,webp
    decode_file("tux.txt","tux1.jpg");


    return 0;
}
