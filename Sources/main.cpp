#include <string>
#include <iostream>
#include <fstream>
#include <iterator>
#include <cstring>
#include <vector>
#include <filesystem>
#include <border.h>

int main(int argc, char *argv[]){

    std::string oUserName = std::getenv("USERNAME");
    oUserName[0] = toupper(oUserName[0]);

    if(argc >= 2){
        
        cAnalyzeString * oAnalyze = new cAnalyzeString();
        cBorder * oBorder = new cBorder();
        char cUserResp;
        
        std::ifstream oOrigin;
        oOrigin.open(argv[1]);
        
        if (oOrigin.is_open()){
         
            std::string oFileNameWithoutExtension = std::filesystem::path(argv[1]).stem();
            
            std::string oNewNameWhitPath = std::filesystem::path(argv[1]).parent_path();
            oNewNameWhitPath.append("/");
            oNewNameWhitPath.append(oFileNameWithoutExtension);
            oNewNameWhitPath.append("WithBorder.txt");
         
            std::istream_iterator<std::string> input_iterator(oOrigin), end;
            std::vector<std::string> oVector(input_iterator, end);
            
            std::cout << "\nOla, " + oUserName + "!" << std::endl;
            std::cout << "\nForam lidos " << oVector.size() << " registros no arquivo " << argv[1] << std::endl;
            std::cout << "A menor palavra eh " << oAnalyze->WhichIsSmallest(oVector) << " com " << oAnalyze->SizeSmallestString(oVector) << " letras." << std::endl;
            std::cout << "A maior palavra eh " << oAnalyze->WhichIsBiggest(oVector) << " com " << oAnalyze->SizeLargestString(oVector) << " letras." << std::endl;

            oBorder->InsertBorder(oVector);

            oOrigin.close();

            std::ofstream oDestiny;
            oDestiny.open(oNewNameWhitPath);
            
            std::ostream_iterator<std::string> output_iterator(oDestiny, "\n");
            std::copy(std::begin(oVector), std::end(oVector), output_iterator);
            
            oDestiny.close();

            std::cout << "\nFoi criado um novo arquivo COM AS BORDAS em " + oNewNameWhitPath << std::endl;
            std::cout << "Deseja ve-lo: (s/n) ";
            std::cin >> cUserResp;
            std::cout << "\n";
            
            if(cUserResp == 's'){
                std::string oCommand = "cat ";
                oCommand.append(oNewNameWhitPath);
                std::system(oCommand.c_str());
                std::cout << "\nFeito!\nObrigado por usar meu software!\n" << std::endl;
            }else{
                std::cout << "Certo!\nObrigado por usar meu software!\n" << std::endl;
            }

        } else{
            std::cout << oUserName + ", nao foi possivel abrir o arquivo " + argv[1] + "\n" << std::endl;
        }
    } else{
        std::cout << "Ola " + oUserName + "!\n" << "Por favor, apos digitar o nome do programa, insira tambem o caminho do arquivo com a relacao de nomes.\n" << std::endl;
    }
    
    return (0);         
}