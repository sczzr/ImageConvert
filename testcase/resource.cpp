//
// Created by Shawn on 6/2/2022.
//

#include "iostream"
#include "Resource.h"


int main(int argc, const char* argv[])
{
    General::Resource res("E:\\Custom_Project\\Shenzhen_QC\\PersimWear\\firmware\\boards\\bes\\bes2700ibp_qc_bridge");
    std::cout << res.GetPath() << std::endl;
}