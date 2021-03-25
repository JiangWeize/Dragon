#include "CppExtension.h"
#include <algorithm>
namespace dragon
{
namespace tool
{
    std::vector<std::string> Split(const std::string &str, const std::string &delim, int split_times)
    {
        size_t start = 0;
        std::vector<std::string> results;
        int current_split_time = 0;
        if(split_times == 0)
        {
            results.push_back(str);
            return results;
        }
        while(start < str.size()) 
        {
            size_t new_start = str.find(delim, start);
            
            if(new_start != std::string::npos)
            {
                current_split_time += 1;
                if(new_start - start > 0)
                    results.push_back(str.substr(start, new_start));
                start = new_start + delim.size();
                
            }
            else break; 
            if(split_times > 0 && current_split_time >= split_times )
            break;
        }
        if( start < str.size())
        results.push_back(str.substr(start, str.size()));
        return results;
    }
    std::vector<std::string> RSplit(const std::string &str, const std::string &delim, int split_times)
    {
        size_t end = str.size();
        std::vector<std::string> results;
        int current_split_time = 0;
        if(split_times == 0)
        {
            results.push_back(str);
            return results;
        }
        while(end > 0)
        {
            
            size_t new_end = str.rfind(delim, end);
            if(new_end != std::string::npos)
            {
                current_split_time += 1;
                if(end - new_end - delim.size() > 0)
                    results.push_back(str.substr(new_end + delim.size(), end));
                end = new_end;
            }
            else break; 
            if(split_times > 0 && current_split_time >= split_times)
            break;
        }
        if( end > 0)
        results.push_back(str.substr(0, end));

        std::reverse(results.begin(), results.end());
        return results;
    }
    bool DirExists(const std::string & folder_name)
    {
        struct stat st;
        if(stat(folder_name.c_str(),&st) == 0)
            if((st.st_mode & S_IFDIR) != 0)
                return true;
        return false;
    }
    bool MakeDir(const std::string & folder_name)
    {
        if(DirExists(folder_name))
        {
            std::cout<<YELLOW<<"[WARNNING]::[MakeDir]::Directory exsits!"<<RESET<<std::endl;
            return true;            
        }
        const int dir_err = mkdir(folder_name.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
        if (-1 == dir_err)
        {
            std::cout<<RED<<"[ERROR]::[MakeDir]::Error creating directory!"<<RESET<<std::endl;
            return false;
        }
        return true;
    }
    geometry::ScalarList LinSpace(double min_n, double max_n, size_t n)
    {
        double step = (max_n - min_n) / n;
        geometry::ScalarList res;
        for(size_t i = 0; i != n; ++i)
        {
            res.push_back(i * step + min_n);
        }
        if(res.back() > max_n) res.back() = max_n;
        return res;
    }
}
}