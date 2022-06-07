//
// Created by Shawn on 6/2/2022.
//

#include "iostream"
#include "resource.h"


int main(int argc, const char* argv[])
{
    General::Resource res("E:/Custom_Project/Shenzhen_QC/PersimWear/firmware/boards/bes/bes2700ibp_qc_bridge/66.png");
    std::cout << res.GetPath() << std::endl;
    std::cout << res.GetFileName() << std::endl;
    std::cout << res.GetFileType() << std::endl;
}