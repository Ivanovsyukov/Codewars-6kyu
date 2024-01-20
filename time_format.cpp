#include <string>

std::string format_duration(int seconds) {
    if (seconds==0){
        return "now";
    }
    int time[5]={};
    int count=0;
    int ost;

    ost=seconds%60;
    if (ost>0){
        count++;
    }
    time[0]=ost;

    seconds/=60;
    ost=seconds%60;
    if (ost>0){
        count++;
    }
    time[1]=ost;

    seconds/=60;
    ost=seconds%24;
    if (ost>0){
        count++;
    }
    time[2]=ost;

    seconds/=24;
    ost=seconds%365;
    if (ost>0){
        count++;
    }
    time[3]=ost;
    seconds/=365;
    time[4]=seconds;
    if (seconds>0){
        count++;
    }
    std::string result;
    for(int i=4; i>=0 && count>0; --i){
        if (time[i]>0){
            result=result+std::to_string(time[i])+" ";
            switch (i){
                case 0:
                    result=result+"second";
                    break;
                case 1:
                    result=result+"minute";
                    break;
                case 2:
                    result=result+"hour";
                    break;
                case 3:
                    result=result+"day";
                    break;
                case 4:
                    result=result+"year";
                break;

                default:
                    break;
            }
            if (time[i]>1){
                result=result+'s';
            }
            if (count>2){
                result=result+", ";
            } else if (count==2){
                result=result+" and ";
            }
            count--;
        }
    }
    return result;
}