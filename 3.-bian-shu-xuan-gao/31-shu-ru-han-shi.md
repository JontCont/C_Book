# 3-1 輸入函式

## Scanf\(\) 輸入函式

`Scanf("%f", &miles);` 

{% hint style="info" %}
🧙♂ **說明 :**

Scanf\("格式", &變數\);
{% endhint %}

呼叫 scanf\(\) 複製資料至變數 miles，miles 資料 是從標準輸入裝置而取得資料。輸入裝置可能會是鍵盤之類的輸入裝置，電腦都會將資料傳送到miles 傳送。

## ⏳ `&` 字元作用

scanf\(\)，是將&字元加在變數前，**& 是 位址運算元 的意思**，會告訴scanf\(\) 要接收新的值的變數會在何處，若沒有加上 &，scanf 只會知道現有的值，卻不能知道記憶體位置，所以無法將新的值傳入現有的變數。

```c
printf("enter two integer >> ");
scanf("%d %d",&m , &n);
m =m+5;
n = (n++);
printf("m = %d \n n =%d\n",m ,n);
```

