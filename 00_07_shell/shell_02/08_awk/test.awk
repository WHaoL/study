BEGIN{
    #输出表头
    printf("产品名\t库名\n");
    #定义一个变量，存储库存总量
    sum=0;
}
$2<75 {
    print $1,$2,"reorder";
}
$2>=75 {
    print $1,$2;
}
{
    sum+=$2;
}
END{
    printf("库存总量:%d\n",sum);
}

