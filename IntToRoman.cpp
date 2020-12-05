string convertToRoman(int n) 
{
    int number[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string symbol[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    
    string Sol = "";
    int Index = 12;
    
    while(n>0){
        int Div = n / number[Index];
        n /= Div;
        
        while(Div--){
            Sol += symbol[Index];
        }
        
        Index--;
    }
   
   return Sol;
}