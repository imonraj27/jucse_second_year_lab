#include <stdio.h>
#define MAX_STRING_LENGTH 100

#ifndef adtstring

typedef struct string {
    char str[MAX_STRING_LENGTH];
}String;

String take_string() {
    String ss;
    int i=0;
    char c;
    while (scanf("%c", &c) && c!='\n')
    {
        ss.str[i] = c;
        i++;
        if(i==MAX_STRING_LENGTH-1){
            break;
        }
    }

    ss.str[i] = '\0';

    return ss;
    
}

String copy_string(String s){
    String s2;
     int i=0;
    while(s.str[i] != '\0'){
        s2.str[i] = s.str[i];
        i++;
    }

    s2.str[i] = '\0';

    return s2;

}

void print_string(String s){
    int i=0;
    while(s.str[i] != '\0'){
        printf("%c", s.str[i]);
        i++;
    }
}

int length_string(String s){
    int i=0;
    while(s.str[i] != '\0'){
        i++;
    }

    return i;
}

int compare_string(String s1, String s2){
    int i=0;
    while(s1.str[i] != '\0' && s2.str[i] != '\0'){
        if(s1.str[i] > s2.str[i]){
            return 1;
        } else if(s1.str[i] < s2.str[i]){
            return -1;
        }
        i++;
        if(i==MAX_STRING_LENGTH){
            return 0;
        }
    }

    if(s1.str[i] !='\0' && s2.str[i] == '\0'){
        return 1;
    }else if(s1.str[i] =='\0' && s2.str[i] != '\0'){
        return -1;
    }else{
        return 0;
    }
}

String into_uppercase(String s){
    int i=0;
    while (s.str[i] != '\0')
    {
        if(s.str[i] >= 97 && s.str[i] <= 122){
            s.str[i] -= 32;
        }
        i++;
    }

    return s;
    
}


String into_lowercase(String s){
    int i=0;
    while (s.str[i] != '\0')
    {
        if(s.str[i] >= 65 && s.str[i] <= 90){
            s.str[i] += 32;
        }
        i++;
    }

    return s;
    
}

String concat_string(String s1, String s2){
    String sss;
    int len1 = length_string(s1);
    int len2 = length_string(s2);
    int length = len1+len2;

    if(length>MAX_STRING_LENGTH){
        printf("\nThe concated string is out of size range..");
        return sss;
    }

     int i=0;
    for(i=0; i<len1; i++){
        sss.str[i] = s1.str[i];
    } 

    for(i=0; i<len2; i++){
        sss.str[len1+i] = s2.str[i];
    }   

    sss.str[len1+len2] = '\0';

    return sss; 
   
}



#define adtstring
#endif