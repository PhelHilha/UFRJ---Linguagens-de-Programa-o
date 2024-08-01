//Desempenho da turma
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "desempenho.cpp"
using namespace std;
void topDesempenho(int p, Disciplina di1,Disciplina di2,Disciplina di3,Disciplina di4,Disciplina di5){
        vector <double> final;
        vector <string> melhor;
        vector <string> neutro;
        vector <string> pior;
        final.push_back(di1.mediaMovel(p)/di1.mediaMovel(p-1));
        final.push_back(di2.mediaMovel(p)/di2.mediaMovel(p-1));
        final.push_back(di3.mediaMovel(p)/di3.mediaMovel(p-1));
        final.push_back(di4.mediaMovel(p)/di4.mediaMovel(p-1));
        final.push_back(di5.mediaMovel(p)/di5.mediaMovel(p-1));
	for (int y = 0; y < 1;y++){
        if(final[0]> 1.05){melhor.push_back("Matematica");}
        if(final[0]<= 1.05 && final[0] >= 1){neutro.push_back("Matematica");}
        if(final[0]< 1){pior.push_back("Matematica");}
        if(final[1]> 1.05){melhor.push_back("Portugues");}
        if(final[1]<= 1.05 && final[1] >= 1){neutro.push_back("Portugues");}
        if(final[1]< 1){pior.push_back("Portugues");}
        if(final[2]> 1.05){melhor.push_back("Filosofia");}
        if(final[2]<= 1.05 && final[2] >= 1){neutro.push_back("Filosofia");}
        if(final[2]< 1){pior.push_back("Filosofia");}
        if(final[3]> 1.05){melhor.push_back("Almoso");}
        if(final[3]<= 1.05 && final[3] >= 1){neutro.push_back("Almoso");}
        if(final[3]< 1){pior.push_back("Almoso");}
        if(final[4]> 1.05){melhor.push_back("Comp");}
        if(final[4]<= 1.05 && final[4] >= 1){neutro.push_back("Comp");}
        if(final[4]< 1){pior.push_back("Comp");}
	}
        cout<<"Diciplinas que tiveram melhora no desempenho:"<<endl;
        for(size_t i = 0; i < melhor.size();i++){
            cout<<melhor.at(i)<<endl;
        }
        cout<<"Diciplinas que tiveram desempenho neutro:"<<endl;
        for(size_t i = 0; i < neutro.size();i++){
            cout<<neutro.at(i)<<endl;
        }
        cout<<"Diciplinas que tiveram desempenho pior:"<<endl;
        for(size_t i = 0; i < pior.size();i++){
            cout<<pior.at(i)<<endl;
        }
        cout<<""<<endl;
        }
void topDisciplica(int p, Disciplina di1,Disciplina di2,Disciplina di3,Disciplina di4,Disciplina di5){
    if (di1.getMedia(p) >= di2.getMedia(p) && di1.getMedia(p) >= di3.getMedia(p) && di1.getMedia(p) >= di4.getMedia(p) && di1.getMedia(p) >= di5.getMedia(p)){
        cout<<"A disciplica Matematica possui as melhores notas finais"<<endl;
    }
    if (di2.getMedia(p) >= di1.getMedia(p) && di2.getMedia(p) >= di3.getMedia(p) && di2.getMedia(p) >= di4.getMedia(p) && di2.getMedia(p) >= di5.getMedia(p)){
        cout<<"A disciplica Portugues possui as melhores notas finais"<<endl;
    }
    if (di3.getMedia(p) >= di1.getMedia(p) && di3.getMedia(p) >= di2.getMedia(p) && di3.getMedia(p) >= di4.getMedia(p) && di3.getMedia(p) >= di5.getMedia(p)){
        cout<<"A disciplica Filosofia possui as melhores notas finais"<<endl;
    }
    if (di4.getMedia(p) >= di1.getMedia(p) && di4.getMedia(p) >= di2.getMedia(p) && di4.getMedia(p) >= di3.getMedia(p) && di4.getMedia(p) >= di5.getMedia(p)){
        cout<<"A disciplica Almoso possui as melhores notas finais"<<endl;
    }
    if (di5.getMedia(p) >= di1.getMedia(p) && di5.getMedia(p) >= di2.getMedia(p) && di5.getMedia(p) >= di3.getMedia(p) && di5.getMedia(p) >= di4.getMedia(p)){
        cout<<"A disciplica Comp possui as melhores notas finais"<<endl;
    }
}
void topMelhora(int p, Disciplina di1,Disciplina di2,Disciplina di3,Disciplina di4,Disciplina di5){
        vector <double> final;
        vector <string> melhor;
        final.push_back(di1.mediaMovel(p-1)/di1.mediaMovel(p-2));
        final.push_back(di2.mediaMovel(p-1)/di2.mediaMovel(p-2));
        final.push_back(di3.mediaMovel(p-1)/di3.mediaMovel(p-2));
        final.push_back(di4.mediaMovel(p-1)/di4.mediaMovel(p-2));
        final.push_back(di5.mediaMovel(p-1)/di5.mediaMovel(p-2));
        if(final[0] > 1.05 && final[0]>= final[1] && final[0]>= final[2]&& final[0]>= final[3]&& final[0]>= final[4]){
            cout<<"Disciplina com maior evolucao : Matematica"<<endl; }
        if(final[1] > 1.05 && final[1]>= final[0] && final[1]>= final[2]&& final[1]>= final[3]&& final[1]>= final[4]){
            cout<<"Disciplina com maior evolucao : Portugues"<<endl; }
        if(final[2] > 1.05 && final[2]>= final[1] && final[2]>= final[0]&& final[0]>= final[2]&& final[2]>= final[4]){
            cout<<"Disciplina com maior evolucao : Filosofia"<<endl; }
        if(final[3] > 1.05 && final[3]>= final[1] && final[3]>= final[2]&& final[3]>= final[0]&& final[3]>= final[4]){
            cout<<"Disciplina com maior evolucao : Almoso"<<endl; }
        if(final[4] > 1.05 && final[4]>= final[1] && final[4]>= final[2]&& final[4]>= final[3]&& final[4]>= final[0]){
            cout<<"Disciplina com maior evolucao : Comp"<<endl; }


}

int main(){
    srand((unsigned) time(0));
    cout<<"Defina o numero de periodos(max 7, min 4)"<<endl;
    int x;
    cin>>x;
    int p;
    if (x>7 or x < 4){p = 4;}
    else {p = x;}
    cout<<"Defina o numero de alunos(max 10, min 3)"<<endl;
    int z;
    int a;
    cin>>z;
    if (z>10 or x < 3){a = 3;}
    else {a = z;}
    Aluno aluno1(p);
    Aluno aluno2(p);
    Aluno aluno3(p);
    Aluno aluno4(p);
    Aluno aluno5(p);
    Aluno aluno6(p);
    Aluno aluno7(p);
    Aluno aluno8(p);
    Aluno aluno9(p);
    Aluno aluno10(p);

    Disciplina Mat(p,a);
    Disciplina Port(p,a);
    Disciplina Filo(p,a);
    Disciplina Almoso(p,a);
    Disciplina Comp(p,a);

    Mat.insereAluno(aluno1);
    Mat.insereAluno(aluno2);
    Mat.insereAluno(aluno3);
    Mat.insereAluno(aluno4);
    Mat.insereAluno(aluno5);
    Mat.insereAluno(aluno6);
    Mat.insereAluno(aluno7);
    Mat.insereAluno(aluno8);
    Mat.insereAluno(aluno9);
    Mat.insereAluno(aluno10);
    Comp.insereAluno(aluno1);
    Comp.insereAluno(aluno2);
    Comp.insereAluno(aluno3);
    Comp.insereAluno(aluno4);
    Comp.insereAluno(aluno5);
    Comp.insereAluno(aluno6);
    Comp.insereAluno(aluno7);
    Comp.insereAluno(aluno8);
    Comp.insereAluno(aluno9);
    Comp.insereAluno(aluno10);
    Port.insereAluno(aluno1);
    Port.insereAluno(aluno2);
    Port.insereAluno(aluno3);
    Port.insereAluno(aluno4);
    Port.insereAluno(aluno5);
    Port.insereAluno(aluno6);
    Port.insereAluno(aluno7);
    Port.insereAluno(aluno8);
    Port.insereAluno(aluno9);
    Port.insereAluno(aluno10);
    Filo.insereAluno(aluno1);
    Filo.insereAluno(aluno2);
    Filo.insereAluno(aluno3);
    Filo.insereAluno(aluno4);
    Filo.insereAluno(aluno5);
    Filo.insereAluno(aluno6);
    Filo.insereAluno(aluno7);
    Filo.insereAluno(aluno8);
    Filo.insereAluno(aluno9);
    Filo.insereAluno(aluno10);
    Almoso.insereAluno(aluno1);
    Almoso.insereAluno(aluno2);
    Almoso.insereAluno(aluno3);
    Almoso.insereAluno(aluno4);
    Almoso.insereAluno(aluno5);
    Almoso.insereAluno(aluno6);
    Almoso.insereAluno(aluno7);
    Almoso.insereAluno(aluno8);
    Almoso.insereAluno(aluno9);
    Almoso.insereAluno(aluno10);
    Mat.defMedMat();
    Port.defMedPort();
    Filo.defMedFilo();
    Almoso.defMedAlmoso();
    Comp.defMedComp();
        for (int i = 0;i < 20; i++){
        cout<<"Escolha qual opcao deseja executar:"<<endl;
        int x = 0;
        cin>>x;
        for(int h = 0; h < 1; h++){
        if (x==1){
            int per;
            cout<<"insira o periodo para media movel:"<<endl;
            cin>>per;
                cout<<"Matematica : Media Movel no periodo-"<<per<<endl<<Mat.mediaMovel(per)<<endl;
                cout<<"Portugues : Media Movel no periodo-"<<per<<endl<<Port.mediaMovel(per)<<endl;
                cout<<"Filosofia : Media Movel no periodo-"<<per<<endl<<Filo.mediaMovel(per)<<endl;
                cout<<"Almoso : Media Movel no periodo-"<<per<<endl<<Almoso.mediaMovel(per)<<endl;
                cout<<"Comp : Media Movel no periodo-"<<per<<endl<<Comp.mediaMovel(per)<<endl;                
            }

            if (x==2){
                topDesempenho(p,Mat,Port,Filo,Almoso,Comp);
            }
            if (x==3){
                cout<<"Desempenho dos alunos:"<<endl;
                for(int b=0; b < a;b++){
                    if(b == 0){
                    cout<<"Aluno 1"<<endl;
                    aluno1.mediaMovel();
	            cout<<endl<<endl;		
                    }
                    if(b == 1){
                    cout<<"Aluno 2 "<<endl;
                    aluno2.mediaMovel();
	            cout<<endl<<endl;
                    }
                    if(b == 2){
                    cout<<"Aluno 3"<<endl;
                    aluno3.mediaMovel();
                    cout<<endl<<endl;
                    }
                    if(b == 3){
                    cout<<"Aluno 4"<<endl;
                    aluno4.mediaMovel();
                    cout<<endl<<endl;
                    }
                    if(b == 4){
                    cout<<"Aluno 5"<<endl;
                    aluno5.mediaMovel();
		    cout<<endl<<endl;
                    }
                    if(b == 5){
                    cout<<"Aluno 6"<<endl;
                    aluno6.mediaMovel();
 		    cout<<endl<<endl;
                    }
                    if(b == 6){
                    cout<<"Aluno 7"<<endl;
                    aluno7.mediaMovel();
		    cout<<endl<<endl;
                    }
                    if(b == 7){
                    cout<<"Aluno 8"<<endl;
                    aluno8.mediaMovel();
                    cout<<endl<<endl;
                    }
                    if(b == 8){
                    cout<<"Aluno 9"<<endl;
                    aluno9.mediaMovel();
		    cout<<endl<<endl;
                    }  
                    if(b == 9){
                    cout<<"Aluno 10"<<endl;
                    aluno10.mediaMovel();
		    cout<<endl<<endl;
                    }                   
            }
        }
            if (x==4){
                topDisciplica(p,Mat,Port,Filo,Almoso,Comp);
            }
            if (x==5){
                double temporario = 0;
                string final;
                for (int k = 0; k < a; k++){
                    temporario = aluno1.getMedia();
                    final = "Aluno 1";
                    if(aluno2.getMedia()>temporario){temporario = aluno2.getMedia();final = "Aluno 2";}
                    if(aluno3.getMedia()>temporario){temporario = aluno3.getMedia();final = "Aluno 3";}
                    if(aluno4.getMedia()>temporario){temporario = aluno4.getMedia();final = "Aluno 4";}
                    if(a>4){
                        if(aluno5.getMedia()>temporario){temporario = aluno5.getMedia();final = "Aluno 5";}
                        if(a>5){
                            if(aluno6.getMedia()>temporario){temporario = aluno6.getMedia();final = "Aluno 6";}
                            if(a>6){
                                if(aluno7.getMedia()>temporario){temporario = aluno7.getMedia();final = "Aluno 7";}
                                if(a>7){
                                    if(aluno8.getMedia()>temporario){temporario = aluno8.getMedia();final = "Aluno 8";}
                                    if(a>8){
                                        if(aluno9.getMedia()>temporario){temporario = aluno9.getMedia();final = "Aluno 9";}
                                        if(a>9){
                                        if(aluno10.getMedia()>temporario){temporario = aluno10.getMedia();final = "Aluno 10";}}
                                        }
                                    }
                                }
                            }
                }
            }
            cout<<"O melhor aluno : "<< final << endl;
        }
            if (x==6){
                topMelhora(p,Mat,Port,Filo,Almoso,Comp);
            }
        }
        }
    return 0;
}  
