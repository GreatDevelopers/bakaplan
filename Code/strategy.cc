#include "strategy.h"

Strategy :: Strategy()
{
    total_seats = total_students = total_group_seats = 0;
}

void Strategy :: totalSeats(int strategy)
{
    for(i = 0; i < total_centres; i++)
    {
        for(j = 0; j < total_rooms[i]; j++)
        {
            room_size[i][j] = rows[i][j] * cols[i][j];
            total_seats += room_size[i][j];
            total_group_seats += room_size[i][j] / strategy;
        }
    }
}

void Strategy :: totalStudents()
{
    for(i = 0; i < total_code; i++)
    {
        total_students += sub_totalrno[i];
    }
}

void Strategy :: totalGroupStudents(int strategy)
{
    s = 0;
    for(i = 0; i < total_code; i++)
    {
        temp[i] = sub_totalrno[i];
        index_value[i] = 0;
    }
    
    for(i = 0; i < strategy; i++)
    {
        group_student_size[i] = 0;
    }
    
    sort(temp, temp + total_code);
    
    for(i = 0; i < total_code; i++)
    {
        for(j = 0; j < total_code; j++)
        {
            if(temp[j] == sub_totalrno[i])
            {
                if(index_value[j] == 0)
                {
                    index_value[j] = i;
                    break;
                }
                
            }
        }
    }
    
    for(i = 0; i < total_code; i++)
    {
        if(s == strategy)
            s = 0;
        group_student_size[s] += sub_totalrno[index_value[i]];
        s++;
               
    }
    sort(group_student_size, group_student_size + strategy);
    
/*    for(i = 0; i < strategy; i++)
    {
        cout << " grp size " 
             << group_student_size[i] << endl;
    }
    
     displaying sorted array
    for(i = 0; i < total_code; i++)
    {
        cout << sub_totalrno[i] << "\t" << i << endl;
    }
    
    cout << endl;
    
    for(i = 0; i < total_code; i++)
    {
        cout << temp[i] << "\t" << i << "\t" << sub_totalrno[index_value[i]] << "\t";
        cout << index_value[i] << "\t" << endl;
    }

  */  
}

void Strategy :: groupCondition(int strategy)
{
    if(group_student_size[strategy-1] > total_group_seats)
    {
        int extra = (group_student_size[strategy-1] - total_group_seats);
        extra = extra * strategy;
        cout << "\t condition in valid" << endl
             << "\t Add " << extra << " more seats." << endl;
        
//        for(i = 0; i < total_centres; i++)
//        {
//            for(j = 0; j < total_rooms[i]; j++)
//            {
//                if((room_size[i][j] / strategy) > extra)
//                {    
//                    //extra = room_size[i][j] / strategy;
//                    
//                    cout << "Add " <<  extra << " seats  (" << rows[i][j]
//                         << " * " << cols[i][j] << " "
//                         << " room)" << endl;
//                    break;
//                }
//            }
//        }
        
        
    }
    else
    {
        cout << "\t condition is valid" << endl;
        seatingPlan(strategy);
        showSeatPlan();
        Report :: Main();
    }
}

void Strategy :: checkValidation(int strategy)
{
    totalSeats(strategy);
    totalStudents();
    totalGroupStudents(strategy);
    
    cout << "\n\t Total Seats = " << total_seats << endl
         << "\t Total Students = " << total_students << endl
         << "\t Total Group Seats = " << total_group_seats << endl
         << "\t Max Group Students = " << group_student_size[strategy-1] << endl;
    
    if(total_seats < total_students)
        cout << "\t Add More rooms!" << endl;
    else
        groupCondition(strategy);
}
        
void Strategy :: chooseStrategy()
{
    do
    {
        system("clear");
    
        cout<<"Select Strategy and enter your choice"<<endl
            <<"\n1. Group of classes"<<endl
            <<"\tA\tA\tA\t"<<endl
            <<"\tA\tA\tA\t"<<endl
            <<"\n2. Group of classes"<<endl
            <<"\tA\tB\tA\t"<<endl
            <<"\tB\tA\tB\t"<<endl
            <<"\n3. Group of classes"<<endl
            <<"\tA\tC\tA\t"<<endl
            <<"\tB\tA\tB\t"<<endl
            <<"\tC\tB\tC\t"<<endl
            <<"\n4. Group of classes"<<endl
            <<"\tA\tC\tA\t"<<endl
            <<"\tB\tD\tB\t"<<endl
            <<"\tC\tA\tC\t"<<endl
            <<"\tD\tB\tD\t"<<endl
            <<"\nEnter your choice:\n";
        
        cin >> strategy_choice;
        switch(strategy_choice)
        {
            case 1:
                checkValidation(strategy_choice);
                break;
            case 2:
                checkValidation(strategy_choice);
                break;
            case 3:
                checkValidation(strategy_choice);
                break;
            case 4:
                checkValidation(strategy_choice);
                break;
            /*	case 2:
                checkValidation(strategyChoice);
                break;
            */
            default:
                cout<<"Oops!!! Wrong choice\n Enter your choice Again\n";
        }

    }while(strategy_choice < 1 || strategy_choice > 4);
}

void Strategy :: Main()
{
    readSubjectWiseRollNo(Subjectwise_Rollno_out);
    readRoomDetails(Input_Rooms);
    chooseStrategy();
}
