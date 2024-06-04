#include <TMath.h>
void Scat(){
	Double_t det = 0.0025;
	Double_t dis = 2;
	Double_t ang =TMath::ATan(0.025/2)*180/3.1415926;
	Double_t eff = 0.95;

	TFile *evgen_2 = new TFile("~/EvGen/out/5cm/compton_p_200_in.root");
	TH1F *theta = (TH1F*)evgen_2->Get("h4");
	Double_t tot=theta->Integral(theta->FindBin(0),theta->FindBin(180));
	Double_t p45=theta->Integral(theta->FindBin(45-ang),theta->FindBin(45+ang));
	Double_t val = p45 * eff/tot;
	cout<<val<<endl;



	TFile *evgen_3 = new TFile("~/EvGen/out/5cm/compton_p_300_in.root");
	TH1F *theta3 = (TH1F*)evgen_3->Get("h4");
	Double_t tot3=theta3->Integral(theta3->FindBin(0),theta3->FindBin(180));
	Double_t p45_3=theta3->Integral(theta3->FindBin(45-ang),theta3->FindBin(45+ang));
	Double_t val3 = p45_3 * eff/tot3;
	cout<<val3<<endl;


}
