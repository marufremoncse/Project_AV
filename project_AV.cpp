#include<iostream>
#include<cmath>
#include<cstdio>
#define PI 3.14159
using namespace std;

class shape
{
protected:
    double arm1,arm2,arm3,length,width,height;
public:
    virtual double area();
    virtual double volume();
    friend istream &operator>>(istream &stream,shape &ob);
};
istream &operator>>(istream &stream,shape &ob)
{
    cout<<"arm1: ";
    stream>>ob.arm1;
    cout<<"arm2: ";
    stream>>ob.arm2;
    cout<<"arm3: ";
    stream>>ob.arm3;
    return stream;
}
double shape::area()
{
    double s,d,result;
    s=(arm1+arm2+arm3)/2;
    d=s*(s-arm1)*(s-arm2)*(s-arm2);
    return sqrt(d);
}
double shape::volume()
{
    return 0;
}

class rectangle:public shape
{
public:
    double area();
    friend istream &operator>>(istream &stream,rectangle &ob);
};
istream &operator>>(istream &stream,rectangle &ob)
{
    cout<<"arm1: ";
    stream>>ob.arm1;
    cout<<"arm2: ";
    stream>>ob.arm2;
    return stream;
}
double rectangle::area()
{
    return arm1*arm2;
}

class circle:public shape
{
protected:
    double radius;
public:
    double area();
    friend istream &operator>>(istream &stream,circle &ob);
};
istream &operator>>(istream &stream,circle &ob)
{
    cout<<"radius: ";
    stream>>ob.radius;
    return stream;
}
double circle::area()
{
    return PI*radius*radius;
}

class cube:public shape
{
public:
    double area();
    double volume();
    friend istream &operator>>(istream &stream,cube &ob);
};
istream &operator>>(istream &stream,cube &ob)
{
    cout<<"arm: ";
    stream>>ob.arm1;
    return stream;
}
double cube::area()
{
    return 6*arm1*arm1;;
}
double cube::volume()
{
    return arm1*arm1*arm1;
}

class circle_sphere:public circle
{
public:
    double area();
    double volume();
    friend istream &operator>>(istream &stream,circle_sphere &ob);
};
istream &operator>>(istream &stream,circle_sphere &ob)
{
    cout<<"radius: ";
    stream>>ob.radius;
    return stream;
}
double circle_sphere::area()
{
    return 4*PI*radius*radius;
}
double circle_sphere::volume()
{
    return (4*PI*radius*radius*radius)/3;
}

class cylinder:public circle
{
public:
    double area();
    double volume();
    friend istream &operator>>(istream &stream,cylinder &ob);
};
istream &operator>>(istream &stream,cylinder &ob)
{
    cout<<"height: ";
    stream>>ob.height;
    cout<<"radius: ";
    stream>>ob.radius;
    return stream;
}
double cylinder::area()
{
    return 2*((PI*radius*height)+(PI*radius*radius));
}
double cylinder::volume()
{
    return PI*radius*radius*height;
}

class rhombus:public rectangle
{
    double dia1,dia2;
public:
    double area();
    friend istream &operator>>(istream &stream,rhombus &ob);
};
istream &operator>>(istream &stream,rhombus &ob)
{
    cout<<"dia1: ";
    stream>>ob.dia1;
    cout<<"dia2: ";
    stream>>ob.dia2;
    return stream;
}
double rhombus::area()
{
    return .5*dia1*dia2;
}

class trapezoid:public shape
{
public:
    double area();
    friend istream &operator>>(istream &stream,trapezoid &ob);
};
istream &operator>>(istream &stream,trapezoid &ob)
{
    cout<<"arm1: ";
    stream>>ob.arm1;
    cout<<"arm2: ";
    stream>>ob.arm2;
    cout<<"height: ";
    stream>>ob.height;
    return stream;
}
double trapezoid::area()
{
    return .5*(arm1+arm2)*height;
}

class ellipse:public shape
{
    double l_axis,s_axis;
public:
    double area();
    friend istream &operator>>(istream &stream,ellipse &ob);
};
istream &operator>>(istream &stream,ellipse &ob)
{
    cout<<"large axis: ";
    stream>>ob.l_axis;
    cout<<"small axis: ";
    stream>>ob.s_axis;
    return stream;
}
double ellipse::area()
{
    return (PI/4)*l_axis*s_axis;
}

class hexagon:public shape
{
public:
    double area();
    friend istream &operator>>(istream &stream,hexagon &ob);
};
istream &operator>>(istream &stream,hexagon &ob)
{
    cout<<"arm: ";
    stream>>ob.arm1;
    return stream;
}
double hexagon::area()
{
    return 2.6*arm1*arm1;
}
class octagon:public shape
{
public:
    double area();
    friend istream &operator>>(istream &stream,octagon &ob);
};
istream &operator>>(istream &stream,octagon &ob)
{
    cout<<"arm: ";
    stream>>ob.arm1;
    return stream;
}
double octagon::area()
{
    return 4.83*arm1*arm1;
}

class rectangular_solid:public shape
{
public:
    double area();
    double volume();
    friend istream &operator>>(istream &stream,rectangular_solid &ob);
};
istream &operator>>(istream &stream,rectangular_solid &ob)
{
    cout<<"length: ";
    stream>>ob.length;
    cout<<"height: ";
    stream>>ob.height;
    cout<<"width: ";
    stream>>ob.width;
    return stream;
}
double rectangular_solid::area()
{
    return 2*((length*width)+(length*height)+(height*width));
}
double rectangular_solid::volume()
{
    return length*width*height;
}

class cone:public cylinder
{
public:
    double area();
    double volume();
    friend istream &operator>>(istream &stream,cone &ob);
};
istream &operator>>(istream &stream,cone &ob)
{
    cout<<"height: ";
    stream>>ob.height;
    cout<<"radius: ";
    stream>>ob.radius;
    return stream;
}
double cone::area()
{
    return PI*radius*(radius+sqrt(radius*radius+height*height));
}
double cone::volume()
{
    return (PI*radius*radius*height)/3;
}

void input()
{
    cout<<endl<<"ENTER your choice : "<<endl;
    cout<<" 0  : TO EXIT FROM INPUT DESK"<<endl;
    cout<<" 1  : TRIANGLE"<<endl;
    cout<<" 2  : RECTANGLE"<<endl;
    cout<<" 3  : CIRCLE"<<endl;
    cout<<" 4  : CUBE"<<endl;
    cout<<" 5  : CIRCLE_SPHERE"<<endl;
    cout<<" 6  : CYLINDER"<<endl;
    cout<<" 7  : RHOMBUS"<<endl;
    cout<<" 8  : TRAPEZOID"<<endl;
    cout<<" 9  : ELLIPSE"<<endl;
    cout<<" 10 : HEXAGON"<<endl;
    cout<<" 11 : OCTAGON"<<endl;
    cout<<" 12 : RECTANGULAR SOLID"<<endl;
    cout<<" 13 : RECTANGULAR PRISM"<<endl;
    cout<<" 14 : CONE"<<endl;
}
void show_all(int count,double *a,double *b)
{
    int i;
    cout<<endl<<"AREAs : ";
    for(i=0;i<count;i++)
    {
        cout<<a[i];
        if(i<count-1)
        {
            cout<<", ";
        }
    }
    cout<<endl<<"VOLUMEs : ";
    for(i=0;i<count;i++)
    {
        cout<<b[i];
        if(i<count-1)
        {
            cout<<", ";
        }
    }
    cout<<endl;
}
void get_all_area(int count,double *a,double *b)
{
    double area=0;
    for(int i=0;i<count;i++)
    {
        area=a[i]+area;
    }
    cout<<endl<<"RESULTS"<<endl<<"========"<<endl;
    cout<<"AREA OF ALL 2D AND 3D SHAPE: "<<area<<endl;
    double volume=0;
    for(int i=0;i<count;i++)
    {
        volume=b[i]+volume;
    }
    cout<<"VOLUME OF ALL 3D SHAPE: "<<volume<<endl;
}
void func_choice()
{
    cout<<"WHAT DO YOU WANT?"<<endl;
    cout<<" 1:  GET PARTICULAR AREA & VOLUME OF DIFFERENT SHAPE"<<endl;
    cout<<" 2:  REMOVE ANY AREA & VOLUME OF DIFFERENT SHAPE"<<endl;
    cout<<" 3:  GET AREA & VOLUME OF SAME TYPES OF SHAPE"<<endl;
    cout<<" 4:  GET WHOLE AREA & VOLUME"<<endl;
    cout<<" 5:  SHOW ALL AREA & VOLUME"<<endl;
    cout<<" 6:  DELETE ALL MEMORY"<<endl;
    cout<<" 7:  EXIT FROM INPUT DESK"<<endl;
}
void get_par_av(int a,double *b,double *c,char *ch)
{
    int i;
    double sum1=0,sum2=0;
    for(i=0;i<=a;i++)
    {
        sum1=sum1+b[i];
        sum2=sum2+c[i];
    }
    cout<<endl<<"Area of all "<<ch<<": "<<sum1<<endl;
    cout<<"Volume of all "<<ch<<": "<<sum2<<endl;
}
void add_av(double &s1,double &s2,double *a,double *b)
{
    int d,i,c;
    cout<<"TYPE THE NUMBER OF SHAPEs, YOU WANT TO ADD."<<endl;
    cin>>i;
    for(d=0;d<i;d++)
    {
        cout<<"ENTER SHAPE NUMBER : ";
        cin>>c;
        s1=s1+a[c-1];
        s2=s2+b[c-1];
    }
    cout<<endl<<"AREA OF DIFFERENT SHAPE : "<<s1<<endl;
    cout<<"VOLUME OF DIFFERENT SHAPE : "<<s2<<endl;
}
void remove_av(double &s1,double &s2,double *a,double *b)
{
    int i,d,c;
    cout<<"TYPE THE NUMBER OF SHAPEs, YOU WANT TO REMOVE"<<endl;
    cin>>i;
    for(d=0;d<i;d++)
    {
        cout<<"ENTER SHAPE NUMBER : ";
        cin>>c;
        s1=s1-a[c-1];
        s2=s2-b[c-1];
    }
    cout<<endl<<"AFTER REMOVING, AREA OF DIFFERENT SHAPE : "<<s1<<endl;
    cout<<"                VOLUME OF DIFFERENT SHAPE : "<<s2<<endl;
}
int main()
{
    double all_shape_ar[500];
    double all_shape_vol[500];
    double ar[14][100];
    double vol[14][100];
    int a[14],n,g,j;
    int count=0;
    double sum1=0,sum2=0,sum=0;
    shape tri;
    rectangle rec;
    circle cir;
    cube cub;
    circle_sphere cs;
    cylinder cl;
    rhombus rmb;
    trapezoid tra;
    ellipse ell;
    hexagon hex;
    octagon octa;
    rectangular_solid rs;
    rectangular_solid rp;
    cone cn;
    cout<<"--------------------SHAPE-------------------"<<endl;
    cout<<"PRESS ANY NUMBER TO CONTINUE OR '0' TO EXIT."<<endl;
    cin>>n;
    while(n)
    {
        input();
        cout<<" 15 : GET  AREA  AND  VOLUME"<<endl<<endl;
        cout<<"CHOICE NUMBER : ";
        cin>>j;
        cout<<endl;
        if(j==0)
        {
            goto finish;
        }
        switch(j)
        {
        case 1:
            cout<<"Shape "<<count+1<<": "<<"TRIANGLE"<<endl;
            cin>>tri;
            all_shape_ar[count]=ar[0][a[0]]=tri.area();
            all_shape_vol[count]=vol[0][a[0]]=tri.volume();
            a[0]++;
            count++;
            break;
        case 2:
            cout<<"Shape "<<count+1<<": "<<"RECTANGLE"<<endl;
            cin>>rec;
            all_shape_ar[count]=ar[1][a[1]]=rec.area();
            all_shape_vol[count]=vol[1][a[1]]=rec.volume();
            a[1]++;
            count++;
            break;
        case 3:
            cout<<"Shape "<<count+1<<": "<<"CIRCLE"<<endl;
            cin>>cir;
            all_shape_ar[count]=ar[2][a[2]]=cir.area();
            all_shape_vol[count]=vol[2][a[2]]=cir.volume();
            a[2]++;
            count++;
            break;
        case 4:
            cout<<"Shape "<<count+1<<": "<<"CUBE"<<endl;
            cin>>cub;
            all_shape_ar[count]=ar[3][a[3]]=cub.area();
            all_shape_vol[count]=vol[3][a[3]]=cub.volume();
            a[3]++;
            count++;
            break;
        case 5:
            cout<<"Shape "<<count+1<<": "<<"CIRCLE_SPHERE"<<endl;
            cin>>cs;
            all_shape_ar[count]=ar[4][a[4]]=cs.area();
            all_shape_vol[count]=vol[4][a[4]]=cs.volume();
            a[4]++;
            count++;
            break;
        case 6:
            cout<<"Shape "<<count+1<<": "<<"CYLINDER"<<endl;
            cin>>cl;
            all_shape_ar[count]=ar[5][a[5]]=cl.area();
            all_shape_vol[count]=vol[5][a[5]]=cl.volume();
            a[5]++;
            count++;
            break;
        case 7:
            cout<<"Shape "<<count+1<<": "<<"RHOMBUS"<<endl;
            cin>>rmb;
            all_shape_ar[count]=ar[6][a[6]]=rmb.area();
            all_shape_vol[count]=vol[6][a[6]]=rmb.volume();
            a[6]++;
            count++;
            break;
        case 8:
            cout<<"Shape "<<count+1<<": "<<"TRAPEZOID"<<endl;
            cin>>tra;
            all_shape_ar[count]=ar[7][a[7]]=tra.area();
            all_shape_vol[count]=vol[7][a[7]]=tra.volume();
            a[7]++;
            count++;
            break;
        case 9:
            cout<<"Shape "<<count+1<<": "<<"ELLIPSE"<<endl;
            cin>>ell;
            all_shape_ar[count]=ar[8][a[8]]=ell.area();
            all_shape_vol[count]=vol[8][a[8]]=ell.volume();
            a[8]++;
            count++;
            break;
        case 10:
            cout<<"Shape "<<count+1<<": "<<"HEXAGON"<<endl;
            cin>>hex;
            all_shape_ar[count]=ar[9][a[9]]=hex.area();
            all_shape_vol[count]=vol[9][a[9]]=hex.volume();
            a[9]++;
            count++;
            break;
        case 11:
            cout<<"Shape "<<count+1<<": "<<"OCTAGON"<<endl;
            cin>>octa;
            all_shape_ar[count]=ar[10][a[10]]=octa.area();
            all_shape_vol[count]=vol[10][a[10]]=octa.volume();
            a[10]++;
            count++;
            break;
        case 12:
            cout<<"Shape "<<count+1<<": "<<"RECTANGULAR_SOLID"<<endl;
            cin>>rs;
            all_shape_ar[count]=ar[11][a[11]]=rs.area();
            all_shape_vol[count]=vol[11][a[11]]=rs.volume();
            a[11]++;
            count++;
            break;
        case 13:
            cout<<"Shape "<<count+1<<": "<<"RECTANGULAR_PRISM"<<endl;
            cin>>rp;
            all_shape_ar[count]=ar[12][a[12]]=rp.area();
            all_shape_vol[count]=vol[12][a[12]]=rp.volume();
            a[12]++;
            count++;
            break;
        case 14:
            cout<<"Shape "<<count+1<<": "<<"CONE"<<endl;
            cin>>cn;
            all_shape_ar[count]=ar[13][a[13]]=cn.area();
            all_shape_vol[count]=vol[13][a[13]]=cn.volume();
            a[13]++;
            count++;
            break;
        case 15:
            int m;
            func_choice();
            cout<<endl<<"CHOICE NUMBER: ";
            cin>>g;
            while(g>0 && g<=7)
            {
                int i,b,c;
                if(g==1)
                {
                    add_av(sum1,sum2,all_shape_ar,all_shape_vol);
                    g=0;
                }
                if(g==2)
                {
                    remove_av(sum1,sum2,all_shape_ar,all_shape_vol);
                    g=0;
                }
                if(g==3)
                {
                    input();
                    cin>>i;
                    switch(i)
                    {
                    case 0:
                        goto here;
                    case 1:
                        get_par_av(a[0],ar[0],vol[0],"TRIANGLEs");
                        break;
                    case 2:
                        get_par_av(a[1],ar[1],vol[1],"RECTANGLEs");
                        break;
                    case 3:
                        get_par_av(a[2],ar[2],vol[2],"CIRCLEs");
                        break;
                    case 4:
                        get_par_av(a[3],ar[3],vol[3],"CUBEs");
                        break;
                    case 5:
                        get_par_av(a[4],ar[4],vol[4],"CIRCLE_SPHEREs");
                        break;
                    case 6:
                        get_par_av(a[5],ar[5],vol[5],"CYLINDERs");
                        break;
                    case 7:
                        get_par_av(a[6],ar[6],vol[6],"RHOMBUSs");
                        break;
                    case 8:
                        get_par_av(a[7],ar[7],vol[7],"TRAPEZOIDs");
                        break;
                    case 9:
                        get_par_av(a[8],ar[8],vol[8],"ELLIPSEs");
                        break;
                    case 10:
                        get_par_av(a[9],ar[9],vol[9],"HEXAGONs");
                        break;
                    case 11:
                        get_par_av(a[10],ar[10],vol[10],"OCTAGONs");
                        break;
                    case 12:
                        get_par_av(a[11],ar[11],vol[11],"RECTANGULAR_SOLIDs");
                        break;
                    case 13:
                        get_par_av(a[12],ar[12],vol[12],"RECTANGULAR_PRISMs");
                        break;
                    case 14:
                        get_par_av(a[13],ar[13],vol[13],"CONEs");
                        break;
                    }
                }
                else if(g==4)
                {
                    get_all_area(count,all_shape_ar,all_shape_vol);
                    g=0;
                }
                else if(g==5)
                {
                    show_all(count,all_shape_ar,all_shape_vol);
                    g=0;
                }
                else if(g==6)
                {
                    for(i=0;i<count;i++)
                    {
                        for(j=0;j<count;j++)
                        {
                            a[i]=ar[i][j]=vol[i][j]=all_shape_ar[i]=0;
                        }
                    }
                    count =0;
                    cout<<"MEMORY CLEARED."<<endl;
                    g=0;
                }
                else if(g==7)
                {
                    goto here;
                }
            }
             break;
        default:
            cout<<"YOU HAVE PRESSED WRONG KEY."<<endl;
            break;
        }
        here:cout<<endl<<"PRESS ANY NUMBER TO RELOAD AND '0' TO EXIT"<<endl;
        cin>>j;
        if(j==0)
        {
            goto finish;
        }
    }
    finish:return 0;
}
