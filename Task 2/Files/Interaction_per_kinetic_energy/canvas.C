#ifdef __CLING__
#pragma cling optimize(0)
#endif
void canvas()
{
//=========Macro generated from canvas: canvas/Histogramas
//=========  (Thu Oct 26 17:56:26 2023) by ROOT version 6.26/06
   TCanvas *canvas = new TCanvas("canvas", "Histogramas",79,66,636,478);
   canvas->Range(-1.875e+13,-5.118751,1.1875e+14,46.06875);
   canvas->SetFillColor(0);
   canvas->SetBorderMode(0);
   canvas->SetBorderSize(2);
   canvas->SetFrameBorderMode(0);
   canvas->SetFrameBorderMode(0);
   
   TH1F *h2__1 = new TH1F("h2__1","",44,-5e+12,1.05e+14);
   h2__1->SetBinContent(3,39);
   h2__1->SetBinContent(4,1);
   h2__1->SetBinContent(7,1);
   h2__1->SetBinContent(11,1);
   h2__1->SetBinContent(21,1);
   h2__1->SetBinContent(43,1);
   h2__1->SetEntries(44);
   h2__1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   h2__1->SetLineColor(ci);
   h2__1->SetLineWidth(5);
   h2__1->GetXaxis()->SetLabelFont(42);
   h2__1->GetXaxis()->SetTitleOffset(1);
   h2__1->GetXaxis()->SetTitleFont(42);
   h2__1->GetYaxis()->SetLabelFont(42);
   h2__1->GetYaxis()->SetTitleFont(42);
   h2__1->GetZaxis()->SetLabelFont(42);
   h2__1->GetZaxis()->SetTitleOffset(1);
   h2__1->GetZaxis()->SetTitleFont(42);
   h2__1->Draw("");
   
   TH1F *h1__2 = new TH1F("h1__2","",44,-5e+12,1.05e+14);
   h1__2->SetBinContent(3,40);
   h1__2->SetBinContent(4,1);
   h1__2->SetBinContent(7,1);
   h1__2->SetBinContent(11,1);
   h1__2->SetBinContent(21,1);
   h1__2->SetEntries(44);

   ci = TColor::GetColor("#0000ff");
   h1__2->SetFillColor(ci);
   h1__2->SetFillStyle(3002);

   ci = TColor::GetColor("#000099");
   h1__2->SetLineColor(ci);
   h1__2->GetXaxis()->SetLabelFont(42);
   h1__2->GetXaxis()->SetTitleOffset(1);
   h1__2->GetXaxis()->SetTitleFont(42);
   h1__2->GetYaxis()->SetLabelFont(42);
   h1__2->GetYaxis()->SetTitleFont(42);
   h1__2->GetZaxis()->SetLabelFont(42);
   h1__2->GetZaxis()->SetTitleOffset(1);
   h1__2->GetZaxis()->SetTitleFont(42);
   h1__2->Draw("SAME");
   
   TLegend *leg = new TLegend(0.729805,0.7841727,0.8788301,0.8848921,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("h1","LOWER","f");

   ci = TColor::GetColor("#0000ff");
   entry->SetFillColor(ci);
   entry->SetFillStyle(3002);

   ci = TColor::GetColor("#000099");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("h2","UPPER","f");
   entry->SetFillStyle(1001);

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(5);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   canvas->Modified();
   canvas->cd();
   canvas->SetSelected(canvas);
}
