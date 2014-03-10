ALU_test
========

這是一支用以產生計組Lab01 ALU測資的程式
用C++寫成，可以自行下載compile使用。

若需要Shifter的測資產生程式請參考[Shifter測資產生程式](http://cyl.femi.tw/co_test.html)

使用方式
========

此程式可以一次產生多筆測資，並輸出至txt檔中，程式啟動後：

1. 將提示選擇產生何種功能的測資（ex加、減），選擇後...
2. 將提示是否亂數產生Src1，輸入y以亂數產生，或輸入n自行輸入...
3. 提示是否亂數產生Src2...
4. 重複步驟1，直到在步驟1選擇-1

程式結束後將會顯示所有測資以及答案，並將測資及答案輸出至檔案中。

建議使用方式
============

為專心測試某一功能(ex加法)，建議程式啟動後，連續輸入15(或更多)次
`1 [Enter] y [Enter] y [Enter]`後輸入-1結束程式。
確認該功能沒有錯誤後，再測其他功能。

Overflow的爭議
==============

- 程式的設計是當運算AND/OR/NOT時，Ans的overflow一定是0，
- 而當運算Addition/Subtraction時，Ans的overflow將會在計算發生溢位時變成1，其餘皆是0
- 當運算Set on less than時，程式預設overflow一定是0，但由於這部分比較有爭議，因此可以將第10行的`#define SET_ON_LESS_THAN_NO_OVERFLOW`移除，則程式就會在運算set on less than且發生溢位時將ans的overflow設為1。

參考資料
========

程式設計皆參考助教的pdf。

Bugs
====

我本身已經測試過大致上沒有問題，但畢竟ALU與測資程式都是由我一個人寫的，
也許會發生一些題意上的誤解，而我自己也沒發現。

若發現程式有任何bug，請直接跟我講、Email or FB告知我、或開一個issue以便一同討論，
謝謝！
