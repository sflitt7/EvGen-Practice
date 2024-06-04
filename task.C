void Integral(){

	TCanvas* c1 = new TCanvas("c1","title",0,0,4000,3000);
	c1->Divide(2,2);
	c1->cd(1);

	TFile *evgen = new TFile("~/EvGen/out/5cm/compton_p_200_in.root");
	TH1F *theta = (TH1F*)evgen->Get("h4");
	theta->GetXaxis()->SetTitle("x axis");
	theta->GetYaxis()->SetTitle("y axis");
	theta->SetFillColor(38);
	Double_t value1= theta->Integral(theta->FindBin(85),theta->FindBin(95));
	Double_t value2= theta->Integral(theta->FindBin(5),theta->FindBin(15));
	Double_t value3= theta->Integral(theta->FindBin(165),theta->FindBin(175));
	Double_t tot= theta->Integral(theta->FindBin(0),theta->FindBin(180));
	cout<<"Around 90 "<<value1/tot<<endl;
	cout<<"Around 10 "<<value2/tot<<endl;
	cout<<"Around 170 "<<value3/tot<<endl;

	theta->Draw();
	c1->cd(2);
	
	TH1F *theta_CM = (TH1F*)evgen->Get("h5");
	theta_CM->GetXaxis()->SetTitle("x axis");
	theta_CM->GetYaxis()->SetTitle("y axis");
	theta_CM->SetFillColor(8);
	Double_t value1CM = theta_CM->Integral(theta_CM->FindBin(85),theta_CM->FindBin(95));
	Double_t value2CM = theta_CM->Integral(theta_CM->FindBin(5),theta_CM->FindBin(15));
	Double_t value3CM = theta_CM->Integral(theta_CM->FindBin(165),theta_CM->FindBin(175));
	Double_t totCM = theta_CM->Integral(theta_CM->FindBin(0),theta_CM->FindBin(180));

	cout<<"CM frame"<<endl;
	cout<<"Around 90 "<<value1CM/totCM<<endl;
	cout<<"Around 10 "<<value2CM/totCM<<endl;
	cout<<"Around 170 "<<value3CM/totCM<<endl;
	
	theta_CM->Draw();

}
