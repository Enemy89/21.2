#include <iostream>
#include <vector>

enum NameRoom {
    bedroom,  kitchen, bathroom, childrens_room, living_room
};

enum NameBuilding {
    house, garage, shed, bathhouse
};

struct room {
    NameRoom name;
    double area;
};

struct floor {
    int count_rooms;
    double cellingHeight;
    std::vector<room> rooms;
};

struct housee {
    int count_floors;
    std::vector<floor> floor;
};

struct building {
    NameBuilding name;
    double area;
    bool hasChimney=false;
    std::vector<housee> house;
};

struct plot {
    int plotNumber;
    std::vector<building> building;
};

struct village {
    std::vector<plot> plot;
};

int main() {
    village settlement;
    std::cout << "Enter number of plots: ";
    int count_plot;
    std::cin >> count_plot;
    for (int i = 0; i < count_plot; ++i) {
        std::cout << "Enter plot number: ";
        int num;
        std::cin>>num;
        plot plot[count_plot];
        plot[i].plotNumber=num;

        std::cout << "Enter number of buildings: ";
        int count_build;
        std::cin >> count_build;
        for (int j = 0; j < count_build; ++j) {
            building build[count_build];
            std::cout << "Enter the type of building (0 - house, 1 - garage, 2 - shed, 3 - bathhouse): ";
            int type_build;
            std::cin>>type_build;
            build[j].name=static_cast<NameBuilding>(type_build);

            std::cout << "Enter the area of the building: ";
            double area_building;
            std::cin>>area_building;
            build[j].area=area_building;

            if (type_build==0 || type_build==3) {
                std::cout << "Does the building have a chimney? (0 - no, 1 - yes): ";
                bool chimney_check;
                std::cin >> chimney_check;
                if (chimney_check==1) {
                    build[j].hasChimney=true;
                }
            }
            else{}

            if (type_build==0) {
                housee house;
                std::cout << "Enter the number of floors in the house: ";
                bool count_floors;
                std::cin >> count_floors;
                house.count_floors=count_floors;
                for (int e=0; e<count_floors;++e) {
                    floor floor[count_floors];
                    std::cout<<"Enter the ceiling height of the "<<e+1<<" floor: ";
                    double celling_height;
                    std::cin>>celling_height;
                    floor[e].cellingHeight=celling_height;

                    std::cout<<"Enter the number of rooms on the "<<e+1<<" floor: ";
                    int count_rooms;
                    std::cin>>count_rooms;
                    floor[e].count_rooms=count_rooms;

                    for (int u=0; u<count_rooms; ++u) {
                        room room[count_rooms];
                        std::cout << "Enter the type of room (0 - bedroom, 1 - kitchen, 2 - bathroom, 3 - children's room, 4 - living room): ";
                        int type_room;
                        std::cin>>type_room;
                        room[u].name=static_cast<NameRoom>(type_room);

                        std::cout<<"Enter room area: ";
                        double area_room;
                        std::cin>>area_room;

                        floor[e].rooms.push_back({room[u].name, area_room});
                    }
                    house.floor.push_back({floor[e].count_rooms, floor[e].cellingHeight, floor[e].rooms});
                }
                build[j].house.push_back({count_floors, house.floor});
            }
            else{}
            plot[i].building.push_back({build[j].name, build[j].area, build[j].hasChimney, build[j].house});
        }
        settlement.plot.push_back({plot[i].plotNumber, plot[i].building});
    }
}
