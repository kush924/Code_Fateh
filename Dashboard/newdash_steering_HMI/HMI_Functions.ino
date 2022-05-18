void hmi_page(String page_num){
    Serial1.print("page page");
    Serial1.print(page_num);
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);
}
void hmi_text(String page_num,String txt_num,int txt ){
    Serial1.print("page");
    Serial1.print(page_num);
    Serial1.print(".");
    Serial1.print("t");
    Serial1.print(txt_num);
    Serial1.print(".");
    Serial1.print("txt=");
    Serial1.print("\"");
    Serial1.print(txt);
    Serial1.print("\"");
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);
}
