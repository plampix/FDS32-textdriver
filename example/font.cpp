#include "font.h"

fdsChar fdsChara;
fdsChar fdsCharb;
fdsChar fdsCharc;
fdsChar fdsChard;
fdsChar fdsChare;
fdsChar fdsCharf;
fdsChar fdsCharg;
fdsChar fdsCharh;
fdsChar fdsChari;
fdsChar fdsCharj;
fdsChar fdsChark;
fdsChar fdsCharl;
fdsChar fdsCharm;
fdsChar fdsCharn;
fdsChar fdsCharo;
fdsChar fdsCharp;
fdsChar fdsCharq;
fdsChar fdsCharr;
fdsChar fdsChars;
fdsChar fdsChart;
fdsChar fdsCharu;
fdsChar fdsCharv;
fdsChar fdsCharw;
fdsChar fdsCharx;
fdsChar fdsChary;
fdsChar fdsCharz;

fdsChar fdsCharA;
fdsChar fdsCharB;
fdsChar fdsCharC;
fdsChar fdsCharD;
fdsChar fdsCharE;
fdsChar fdsCharF;
fdsChar fdsCharG;
fdsChar fdsCharH;
fdsChar fdsCharI;
fdsChar fdsCharJ;
fdsChar fdsCharK;
fdsChar fdsCharL;
fdsChar fdsCharM;
fdsChar fdsCharN;
fdsChar fdsCharO;
fdsChar fdsCharP;
fdsChar fdsCharQ;
fdsChar fdsCharR;
fdsChar fdsCharS;
fdsChar fdsCharT;
fdsChar fdsCharU;
fdsChar fdsCharV;
fdsChar fdsCharW;
fdsChar fdsCharX;
fdsChar fdsCharY;
fdsChar fdsCharZ;

fdsChar fdsChar0;
fdsChar fdsChar1;
fdsChar fdsChar2;
fdsChar fdsChar3;
fdsChar fdsChar4;
fdsChar fdsChar5;
fdsChar fdsChar6;
fdsChar fdsChar7;
fdsChar fdsChar8;
fdsChar fdsChar9;

fdsChar fdsCharColon;
fdsChar fdsCharBang;
fdsChar fdsCharDash;
fdsChar fdsCharSpace;
fdsChar fdsCharComma;
fdsChar fdsCharSingleQuote;
fdsChar fdsCharUnknown;

void initialiseLetters() {
  //include the seperating space
  // These things are easy to edit if you set your editor to highlight 1
  // In vim I do "/1" to search for 1 and ":set hlsearch" to highlight it


  fdsChara.character_map[0] = B00000000;
  fdsChara.character_map[1] = B00000000;
  fdsChara.character_map[2] = B00000110;
  fdsChara.character_map[3] = B00001000;
  fdsChara.character_map[4] = B00001110;
  fdsChara.character_map[5] = B00001001;
  fdsChara.character_map[6] = B00001110;
  fdsChara.width = 5;

  fdsCharb.character_map[0] = B00000000;
  fdsCharb.character_map[1] = B00000000;
  fdsCharb.character_map[2] = B00000001;
  fdsCharb.character_map[3] = B00000001;
  fdsCharb.character_map[4] = B00000111;
  fdsCharb.character_map[5] = B00001001;
  fdsCharb.character_map[6] = B00000111;
  fdsCharb.width = 5;

  fdsCharc.character_map[0] = B00000000;
  fdsCharc.character_map[1] = B00000000;
  fdsCharc.character_map[2] = B00000000;
  fdsCharc.character_map[3] = B00001110;
  fdsCharc.character_map[4] = B00000001;
  fdsCharc.character_map[5] = B00000001;
  fdsCharc.character_map[6] = B00001110;
  fdsCharc.width = 5;

  fdsChard.character_map[0] = B00000000;
  fdsChard.character_map[1] = B00000000;
  fdsChard.character_map[2] = B00001000;
  fdsChard.character_map[3] = B00001000;
  fdsChard.character_map[4] = B00001110;
  fdsChard.character_map[5] = B00001001;
  fdsChard.character_map[6] = B00001110;
  fdsChard.width = 5;

  fdsChare.character_map[0] = B00000000;
  fdsChare.character_map[1] = B00000000;
  fdsChare.character_map[2] = B00000110;
  fdsChare.character_map[3] = B00001001;
  fdsChare.character_map[4] = B00000111;
  fdsChare.character_map[5] = B00000001;
  fdsChare.character_map[6] = B00000110;
  fdsChare.width = 5;

  fdsCharf.character_map[0] = B00000000;
  fdsCharf.character_map[1] = B00000000;
  fdsCharf.character_map[2] = B00000110;
  fdsCharf.character_map[3] = B00000010;
  fdsCharf.character_map[4] = B00000111;
  fdsCharf.character_map[5] = B00000010;
  fdsCharf.character_map[6] = B00000010;
  fdsCharf.width = 4;

  fdsCharg.character_map[0] = B00000000;
  fdsCharg.character_map[1] = B00000000;
  fdsCharg.character_map[2] = B00000110;
  fdsCharg.character_map[3] = B00001001;
  fdsCharg.character_map[4] = B00001110;
  fdsCharg.character_map[5] = B00001000;
  fdsCharg.character_map[6] = B00000110;
  fdsCharg.width = 5;

  fdsCharh.character_map[0] = B00000000;
  fdsCharh.character_map[1] = B00000000;
  fdsCharh.character_map[2] = B00000001;
  fdsCharh.character_map[3] = B00000001;
  fdsCharh.character_map[4] = B00000111;
  fdsCharh.character_map[5] = B00001001;
  fdsCharh.character_map[6] = B00001001;
  fdsCharh.width = 5;

  fdsChari.character_map[0] = B00000000;
  fdsChari.character_map[1] = B00000001;
  fdsChari.character_map[2] = B00000000;
  fdsChari.character_map[3] = B00000001;
  fdsChari.character_map[4] = B00000001;
  fdsChari.character_map[5] = B00000001;
  fdsChari.character_map[6] = B00000001;
  fdsChari.width = 2;

  fdsCharj.character_map[0] = B00000000;
  fdsCharj.character_map[1] = B00000010;
  fdsCharj.character_map[2] = B00000000;
  fdsCharj.character_map[3] = B00000010;
  fdsCharj.character_map[4] = B00000010;
  fdsCharj.character_map[5] = B00000010;
  fdsCharj.character_map[6] = B00000001;
  fdsCharj.width = 3;

  fdsChark.character_map[0] = B00000000;
  fdsChark.character_map[1] = B00000000;
  fdsChark.character_map[2] = B00000001;
  fdsChark.character_map[3] = B00001001;
  fdsChark.character_map[4] = B00000101;
  fdsChark.character_map[5] = B00000011;
  fdsChark.character_map[6] = B00001101;
  fdsChark.width = 5;

  fdsCharl.character_map[0] = B00000000;
  fdsCharl.character_map[1] = B00000000;
  fdsCharl.character_map[2] = B00000001;
  fdsCharl.character_map[3] = B00000001;
  fdsCharl.character_map[4] = B00000001;
  fdsCharl.character_map[5] = B00000001;
  fdsCharl.character_map[6] = B00000010;
  fdsCharl.width = 3;

  fdsCharm.character_map[0] = B00000000;
  fdsCharm.character_map[1] = B00000000;
  fdsCharm.character_map[2] = B00010001;
  fdsCharm.character_map[3] = B00011011;
  fdsCharm.character_map[4] = B00010101;
  fdsCharm.character_map[5] = B00010101;
  fdsCharm.character_map[6] = B00010101;
  fdsCharm.width = 6;

  fdsCharn.character_map[0] = B00000000;
  fdsCharn.character_map[1] = B00000000;
  fdsCharn.character_map[2] = B00000101;
  fdsCharn.character_map[3] = B00001011;
  fdsCharn.character_map[4] = B00001001;
  fdsCharn.character_map[5] = B00001001;
  fdsCharn.character_map[6] = B00001001;
  fdsCharn.width = 5;

  fdsCharo.character_map[0] = B00000000;
  fdsCharo.character_map[1] = B00000000;
  fdsCharo.character_map[2] = B00000110;
  fdsCharo.character_map[3] = B00001001;
  fdsCharo.character_map[4] = B00001001;
  fdsCharo.character_map[5] = B00001001;
  fdsCharo.character_map[6] = B00000110;
  fdsCharo.width = 5;

  fdsCharp.character_map[0] = B00000000;
  fdsCharp.character_map[1] = B00000000;
  fdsCharp.character_map[2] = B00000111;
  fdsCharp.character_map[3] = B00001001;
  fdsCharp.character_map[4] = B00000111;
  fdsCharp.character_map[5] = B00000001;
  fdsCharp.character_map[6] = B00000001;
  fdsCharp.width = 5;

  fdsCharq.character_map[0] = B00000000;
  fdsCharq.character_map[1] = B00000000;
  fdsCharq.character_map[2] = B00001110;
  fdsCharq.character_map[3] = B00001001;
  fdsCharq.character_map[4] = B00001110;
  fdsCharq.character_map[5] = B00001000;
  fdsCharq.character_map[6] = B00001000;
  fdsCharq.width = 5;

  fdsCharr.character_map[0] = B00000000;
  fdsCharr.character_map[1] = B00000000;
  fdsCharr.character_map[2] = B00000101;
  fdsCharr.character_map[3] = B00001011;
  fdsCharr.character_map[4] = B00000001;
  fdsCharr.character_map[5] = B00000001;
  fdsCharr.character_map[6] = B00000001;
  fdsCharr.width = 5;

  fdsChars.character_map[0] = B00000000;
  fdsChars.character_map[1] = B00000000;
  fdsChars.character_map[2] = B00001110;
  fdsChars.character_map[3] = B00000001;
  fdsChars.character_map[4] = B00000110;
  fdsChars.character_map[5] = B00001000;
  fdsChars.character_map[6] = B00000111;
  fdsChars.width = 5;

  fdsChart.character_map[0] = B00000000;
  fdsChart.character_map[1] = B00000000;
  fdsChart.character_map[2] = B00000010;
  fdsChart.character_map[3] = B00000111;
  fdsChart.character_map[4] = B00000010;
  fdsChart.character_map[5] = B00000010;
  fdsChart.character_map[6] = B00000100;
  fdsChart.width = 4;

  fdsCharu.character_map[0] = B00000000;
  fdsCharu.character_map[1] = B00000000;
  fdsCharu.character_map[2] = B00001001;
  fdsCharu.character_map[3] = B00001001;
  fdsCharu.character_map[4] = B00001001;
  fdsCharu.character_map[5] = B00001001;
  fdsCharu.character_map[6] = B00001110;
  fdsCharu.width = 5;

  fdsCharv.character_map[0] = B00000000;
  fdsCharv.character_map[1] = B00000000;
  fdsCharv.character_map[2] = B00010001;
  fdsCharv.character_map[3] = B00010001;
  fdsCharv.character_map[4] = B00001010;
  fdsCharv.character_map[5] = B00001010;
  fdsCharv.character_map[6] = B00000100;
  fdsCharv.width = 6;

  fdsCharw.character_map[0] = B00000000;
  fdsCharw.character_map[1] = B00000000;
  fdsCharw.character_map[2] = B00010001;
  fdsCharw.character_map[3] = B00010101;
  fdsCharw.character_map[4] = B00010101;
  fdsCharw.character_map[5] = B00001010;
  fdsCharw.character_map[6] = B00001010;
  fdsCharw.width = 6;

  fdsCharx.character_map[0] = B00000000;
  fdsCharx.character_map[1] = B00000000;
  fdsCharx.character_map[2] = B00010001;
  fdsCharx.character_map[3] = B00001010;
  fdsCharx.character_map[4] = B00000100;
  fdsCharx.character_map[5] = B00001010;
  fdsCharx.character_map[6] = B00010001;
  fdsCharx.width = 6;

  fdsChary.character_map[0] = B00000000;
  fdsChary.character_map[1] = B00000000;
  fdsChary.character_map[2] = B00001001;
  fdsChary.character_map[3] = B00001001;
  fdsChary.character_map[4] = B00001110;
  fdsChary.character_map[5] = B00001000;
  fdsChary.character_map[6] = B00000110;
  fdsChary.width = 5;

  fdsCharz.character_map[0] = B00000000;
  fdsCharz.character_map[1] = B00000000;
  fdsCharz.character_map[2] = B00001111;
  fdsCharz.character_map[3] = B00001000;
  fdsCharz.character_map[4] = B00000100;
  fdsCharz.character_map[5] = B00000010;
  fdsCharz.character_map[6] = B00001111;
  fdsCharz.width = 5;

  // Capital

  fdsCharA.character_map[0] = B00000110;
  fdsCharA.character_map[1] = B00001001;
  fdsCharA.character_map[2] = B00001001;
  fdsCharA.character_map[3] = B00001111;
  fdsCharA.character_map[4] = B00001001;
  fdsCharA.character_map[5] = B00001001;
  fdsCharA.character_map[6] = B00001001;
  fdsCharA.width = 5;

  fdsCharB.character_map[0] = B00000111;
  fdsCharB.character_map[1] = B00001001;
  fdsCharB.character_map[2] = B00001001;
  fdsCharB.character_map[3] = B00000111;
  fdsCharB.character_map[4] = B00001001;
  fdsCharB.character_map[5] = B00001001;
  fdsCharB.character_map[6] = B00000111;
  fdsCharB.width = 5;

  fdsCharC.character_map[0] = B00000110;
  fdsCharC.character_map[1] = B00001001;
  fdsCharC.character_map[2] = B00000001;
  fdsCharC.character_map[3] = B00000001;
  fdsCharC.character_map[4] = B00000001;
  fdsCharC.character_map[5] = B00001001;
  fdsCharC.character_map[6] = B00000110;
  fdsCharC.width = 5;

  fdsCharD.character_map[0] = B00000111;
  fdsCharD.character_map[1] = B00001001;
  fdsCharD.character_map[2] = B00010001;
  fdsCharD.character_map[3] = B00010001;
  fdsCharD.character_map[4] = B00010001;
  fdsCharD.character_map[5] = B00001001;
  fdsCharD.character_map[6] = B00000111;
  fdsCharD.width = 6;

  fdsCharE.character_map[0] = B00000111;
  fdsCharE.character_map[1] = B00000001;
  fdsCharE.character_map[2] = B00000001;
  fdsCharE.character_map[3] = B00000111;
  fdsCharE.character_map[4] = B00000001;
  fdsCharE.character_map[5] = B00000001;
  fdsCharE.character_map[6] = B00000111;
  fdsCharE.width = 4;

  fdsCharF.character_map[0] = B00000111;
  fdsCharF.character_map[1] = B00000001;
  fdsCharF.character_map[2] = B00000001;
  fdsCharF.character_map[3] = B00000111;
  fdsCharF.character_map[4] = B00000001;
  fdsCharF.character_map[5] = B00000001;
  fdsCharF.character_map[6] = B00000001;
  fdsCharF.width = 4;

  fdsCharG.character_map[0] = B00001110;
  fdsCharG.character_map[1] = B00010001;
  fdsCharG.character_map[2] = B00000001;
  fdsCharG.character_map[3] = B00000001;
  fdsCharG.character_map[4] = B00011101;
  fdsCharG.character_map[5] = B00010001;
  fdsCharG.character_map[6] = B00001110;
  fdsCharG.width = 6;

  fdsCharH.character_map[0] = B00001001;
  fdsCharH.character_map[1] = B00001001;
  fdsCharH.character_map[2] = B00001001;
  fdsCharH.character_map[3] = B00001111;
  fdsCharH.character_map[4] = B00001001;
  fdsCharH.character_map[5] = B00001001;
  fdsCharH.character_map[6] = B00001001;
  fdsCharH.width = 5;

  fdsCharI.character_map[0] = B00000111;
  fdsCharI.character_map[1] = B00000010;
  fdsCharI.character_map[2] = B00000010;
  fdsCharI.character_map[3] = B00000010;
  fdsCharI.character_map[4] = B00000010;
  fdsCharI.character_map[5] = B00000010;
  fdsCharI.character_map[6] = B00000111;
  fdsCharI.width = 4;

  fdsCharJ.character_map[0] = B00001110;
  fdsCharJ.character_map[1] = B00000100;
  fdsCharJ.character_map[2] = B00000100;
  fdsCharJ.character_map[3] = B00000100;
  fdsCharJ.character_map[4] = B00000100;
  fdsCharJ.character_map[5] = B00000101;
  fdsCharJ.character_map[6] = B00000010;
  fdsCharJ.width = 5;

  fdsCharK.character_map[0] = B00001001;
  fdsCharK.character_map[1] = B00001001;
  fdsCharK.character_map[2] = B00000101;
  fdsCharK.character_map[3] = B00000011;
  fdsCharK.character_map[4] = B00000101;
  fdsCharK.character_map[5] = B00001001;
  fdsCharK.character_map[6] = B00001001;
  fdsCharK.width = 5;

  fdsCharL.character_map[0] = B00000001;
  fdsCharL.character_map[1] = B00000001;
  fdsCharL.character_map[2] = B00000001;
  fdsCharL.character_map[3] = B00000001;
  fdsCharL.character_map[4] = B00000001;
  fdsCharL.character_map[5] = B00000001;
  fdsCharL.character_map[6] = B00000111;
  fdsCharL.width = 4;

  fdsCharM.character_map[0] = B00010001;
  fdsCharM.character_map[1] = B00011011;
  fdsCharM.character_map[2] = B00010101;
  fdsCharM.character_map[3] = B00010101;
  fdsCharM.character_map[4] = B00010001;
  fdsCharM.character_map[5] = B00010001;
  fdsCharM.character_map[6] = B00010001;
  fdsCharM.width = 6;

  fdsCharN.character_map[0] = B00010001;
  fdsCharN.character_map[1] = B00010001;
  fdsCharN.character_map[2] = B00010011;
  fdsCharN.character_map[3] = B00010101;
  fdsCharN.character_map[4] = B00011001;
  fdsCharN.character_map[5] = B00010001;
  fdsCharN.character_map[6] = B00010001;
  fdsCharN.width = 6;

  fdsCharO.character_map[0] = B00001110;
  fdsCharO.character_map[1] = B00010001;
  fdsCharO.character_map[2] = B00010001;
  fdsCharO.character_map[3] = B00010001;
  fdsCharO.character_map[4] = B00010001;
  fdsCharO.character_map[5] = B00010001;
  fdsCharO.character_map[6] = B00001110;
  fdsCharO.width = 6;

  fdsCharP.character_map[0] = B00000111;
  fdsCharP.character_map[1] = B00001001;
  fdsCharP.character_map[2] = B00001001;
  fdsCharP.character_map[3] = B00000111;
  fdsCharP.character_map[4] = B00000001;
  fdsCharP.character_map[5] = B00000001;
  fdsCharP.character_map[6] = B00000001;
  fdsCharP.width = 5;

  fdsCharQ.character_map[0] = B00001110;
  fdsCharQ.character_map[1] = B00010001;
  fdsCharQ.character_map[2] = B00010001;
  fdsCharQ.character_map[3] = B00010001;
  fdsCharQ.character_map[4] = B00010001;
  fdsCharQ.character_map[5] = B00001001;
  fdsCharQ.character_map[6] = B00010110;
  fdsCharQ.width = 6;

  fdsCharR.character_map[0] = B00000111;
  fdsCharR.character_map[1] = B00001001;
  fdsCharR.character_map[2] = B00001001;
  fdsCharR.character_map[3] = B00000111;
  fdsCharR.character_map[4] = B00001001;
  fdsCharR.character_map[5] = B00001001;
  fdsCharR.character_map[6] = B00001001;
  fdsCharR.width = 5;

  fdsCharS.character_map[0] = B00000110;
  fdsCharS.character_map[1] = B00001001;
  fdsCharS.character_map[2] = B00000001;
  fdsCharS.character_map[3] = B00000110;
  fdsCharS.character_map[4] = B00001000;
  fdsCharS.character_map[5] = B00001001;
  fdsCharS.character_map[6] = B00000110;
  fdsCharS.width = 5;

  fdsCharT.character_map[0] = B00011111;
  fdsCharT.character_map[1] = B00000100;
  fdsCharT.character_map[2] = B00000100;
  fdsCharT.character_map[3] = B00000100;
  fdsCharT.character_map[4] = B00000100;
  fdsCharT.character_map[5] = B00000100;
  fdsCharT.character_map[6] = B00000100;
  fdsCharT.width = 6;

  fdsCharU.character_map[0] = B00001001;
  fdsCharU.character_map[1] = B00001001;
  fdsCharU.character_map[2] = B00001001;
  fdsCharU.character_map[3] = B00001001;
  fdsCharU.character_map[4] = B00001001;
  fdsCharU.character_map[5] = B00001001;
  fdsCharU.character_map[6] = B00000110;
  fdsCharU.width = 5;

  fdsCharV.character_map[0] = B00010001;
  fdsCharV.character_map[1] = B00010001;
  fdsCharV.character_map[2] = B00010001;
  fdsCharV.character_map[3] = B00001010;
  fdsCharV.character_map[4] = B00001010;
  fdsCharV.character_map[5] = B00001010;
  fdsCharV.character_map[6] = B00000100;
  fdsCharV.width = 6;

  fdsCharW.character_map[0] = B00010001;
  fdsCharW.character_map[1] = B00010101;
  fdsCharW.character_map[2] = B00010101;
  fdsCharW.character_map[3] = B00010101;
  fdsCharW.character_map[4] = B00001010;
  fdsCharW.character_map[5] = B00001010;
  fdsCharW.character_map[6] = B00001010;
  fdsCharW.width = 6;

  fdsCharX.character_map[0] = B00010001;
  fdsCharX.character_map[1] = B00010001;
  fdsCharX.character_map[2] = B00001010;
  fdsCharX.character_map[3] = B00000100;
  fdsCharX.character_map[4] = B00001010;
  fdsCharX.character_map[5] = B00010001;
  fdsCharX.character_map[6] = B00010001;
  fdsCharX.width = 6;

  fdsCharY.character_map[0] = B00010001;
  fdsCharY.character_map[1] = B00010001;
  fdsCharY.character_map[2] = B00001010;
  fdsCharY.character_map[3] = B00000100;
  fdsCharY.character_map[4] = B00000100;
  fdsCharY.character_map[5] = B00000100;
  fdsCharY.character_map[6] = B00000100;
  fdsCharY.width = 6;

  fdsCharZ.character_map[0] = B00011111;
  fdsCharZ.character_map[1] = B00010000;
  fdsCharZ.character_map[2] = B00001000;
  fdsCharZ.character_map[3] = B00000100;
  fdsCharZ.character_map[4] = B00000010;
  fdsCharZ.character_map[5] = B00000001;
  fdsCharZ.character_map[6] = B00011111;
  fdsCharZ.width = 6;

  fdsChar0.character_map[0] = B00001110;
  fdsChar0.character_map[1] = B00010001;
  fdsChar0.character_map[2] = B00011001;
  fdsChar0.character_map[3] = B00010101;
  fdsChar0.character_map[4] = B00010011;
  fdsChar0.character_map[5] = B00010001;
  fdsChar0.character_map[6] = B00001110;
  fdsChar0.width = 6;

  fdsChar1.character_map[0] = B00000100;
  fdsChar1.character_map[1] = B00000110;
  fdsChar1.character_map[2] = B00000101;
  fdsChar1.character_map[3] = B00000100;
  fdsChar1.character_map[4] = B00000100;
  fdsChar1.character_map[5] = B00000100;
  fdsChar1.character_map[6] = B00011111;
  fdsChar1.width = 6;

  fdsChar2.character_map[0] = B00001110;
  fdsChar2.character_map[1] = B00010001;
  fdsChar2.character_map[2] = B00010000;
  fdsChar2.character_map[3] = B00001000;
  fdsChar2.character_map[4] = B00000100;
  fdsChar2.character_map[5] = B00000010;
  fdsChar2.character_map[6] = B00011111;
  fdsChar2.width = 6;

  fdsChar3.character_map[0] = B00001110;
  fdsChar3.character_map[1] = B00010001;
  fdsChar3.character_map[2] = B00010000;
  fdsChar3.character_map[3] = B00001100;
  fdsChar3.character_map[4] = B00010000;
  fdsChar3.character_map[5] = B00010001;
  fdsChar3.character_map[6] = B00001110;
  fdsChar3.width = 6;

  fdsChar4.character_map[0] = B00001000;
  fdsChar4.character_map[1] = B00001100;
  fdsChar4.character_map[2] = B00001010;
  fdsChar4.character_map[3] = B00001001;
  fdsChar4.character_map[4] = B00011111;
  fdsChar4.character_map[5] = B00001000;
  fdsChar4.character_map[6] = B00001000;
  fdsChar4.width = 6;

  fdsChar5.character_map[0] = B00011111;
  fdsChar5.character_map[1] = B00000001;
  fdsChar5.character_map[2] = B00000001;
  fdsChar5.character_map[3] = B00001110;
  fdsChar5.character_map[4] = B00010000;
  fdsChar5.character_map[5] = B00010001;
  fdsChar5.character_map[6] = B00001110;
  fdsChar5.width = 6;

  fdsChar6.character_map[0] = B00001110;
  fdsChar6.character_map[1] = B00000001;
  fdsChar6.character_map[2] = B00000001;
  fdsChar6.character_map[3] = B00001111;
  fdsChar6.character_map[4] = B00010001;
  fdsChar6.character_map[5] = B00010001;
  fdsChar6.character_map[6] = B00001110;
  fdsChar6.width = 6;

  fdsChar7.character_map[0] = B00011111;
  fdsChar7.character_map[1] = B00010000;
  fdsChar7.character_map[2] = B00010000;
  fdsChar7.character_map[3] = B00001000;
  fdsChar7.character_map[4] = B00000100;
  fdsChar7.character_map[5] = B00000010;
  fdsChar7.character_map[6] = B00000001;
  fdsChar7.width = 6;

  fdsChar8.character_map[0] = B00001110;
  fdsChar8.character_map[1] = B00010001;
  fdsChar8.character_map[2] = B00010001;
  fdsChar8.character_map[3] = B00001110;
  fdsChar8.character_map[4] = B00010001;
  fdsChar8.character_map[5] = B00010001;
  fdsChar8.character_map[6] = B00001110;
  fdsChar8.width = 6;

  fdsChar9.character_map[0] = B00001110;
  fdsChar9.character_map[1] = B00010001;
  fdsChar9.character_map[2] = B00010001;
  fdsChar9.character_map[3] = B00011110;
  fdsChar9.character_map[4] = B00010000;
  fdsChar9.character_map[5] = B00010001;
  fdsChar9.character_map[6] = B00001110;
  fdsChar9.width = 6;

  fdsCharColon.character_map[0] = B00000000;
  fdsCharColon.character_map[1] = B00000000;
  fdsCharColon.character_map[2] = B00000001;
  fdsCharColon.character_map[3] = B00000000;
  fdsCharColon.character_map[4] = B00000001;
  fdsCharColon.character_map[5] = B00000000;
  fdsCharColon.character_map[6] = B00000000;
  fdsCharColon.width = 2;

  fdsCharSingleQuote.character_map[0] = B00000001;
  fdsCharSingleQuote.character_map[1] = B00000001;
  fdsCharSingleQuote.character_map[2] = B00000000;
  fdsCharSingleQuote.character_map[3] = B00000000;
  fdsCharSingleQuote.character_map[4] = B00000000;
  fdsCharSingleQuote.character_map[5] = B00000000;
  fdsCharSingleQuote.character_map[6] = B00000000;
  fdsCharSingleQuote.width = 2;

  fdsCharDash.character_map[0] = B00000000;
  fdsCharDash.character_map[1] = B00000000;
  fdsCharDash.character_map[2] = B00000000;
  fdsCharDash.character_map[3] = B00001111;
  fdsCharDash.character_map[4] = B00000000;
  fdsCharDash.character_map[5] = B00000000;
  fdsCharDash.character_map[6] = B00000000;
  fdsCharDash.width = 5;

  fdsCharComma.character_map[0] = B00000000;
  fdsCharComma.character_map[1] = B00000000;
  fdsCharComma.character_map[2] = B00000000;
  fdsCharComma.character_map[3] = B00000000;
  fdsCharComma.character_map[4] = B00000000;
  fdsCharComma.character_map[5] = B00000001;
  fdsCharComma.character_map[6] = B00000001;
  fdsCharComma.width = 2;

  fdsCharBang.character_map[0] = B00000001;
  fdsCharBang.character_map[1] = B00000001;
  fdsCharBang.character_map[2] = B00000001;
  fdsCharBang.character_map[3] = B00000001;
  fdsCharBang.character_map[4] = B00000001;
  fdsCharBang.character_map[5] = B00000000;
  fdsCharBang.character_map[6] = B00000001;
  fdsCharBang.width = 2;

  fdsCharUnknown.character_map[0] = B00000111;
  fdsCharUnknown.character_map[1] = B00000111;
  fdsCharUnknown.character_map[2] = B00000111;
  fdsCharUnknown.character_map[3] = B00000111;
  fdsCharUnknown.character_map[4] = B00000111;
  fdsCharUnknown.character_map[5] = B00000111;
  fdsCharUnknown.character_map[6] = B00000111;
  fdsCharUnknown.width = 4;

  fdsCharSpace.width = 2;
}

fdsChar* charTofdsChar(char value) {
  switch (value) {
    case 'a':
      return &fdsChara;
    case 'A':
      return &fdsCharA;
    case 'b':
      return &fdsCharb;
    case 'B':
      return &fdsCharB;
    case 'c':
      return &fdsCharc;
    case 'C':
      return &fdsCharC;
    case 'd':
      return &fdsChard;
    case 'D':
      return &fdsCharD;
    case 'e':
      return &fdsChare;
    case 'E':
      return &fdsCharE;
    case 'f':
      return &fdsCharf;
    case 'F':
      return &fdsCharF;
    case 'g':
      return &fdsCharg;
    case 'G':
      return &fdsCharG;
    case 'h':
      return &fdsCharh;
    case 'H':
      return &fdsCharH;
    case 'i':
      return &fdsChari;
    case 'I':
      return &fdsCharI;
    case 'j':
      return &fdsCharj;
    case 'J':
      return &fdsCharJ;
    case 'k':
      return &fdsChark;
    case 'K':
      return &fdsCharK;
    case 'l':
      return &fdsCharl;
    case 'L':
      return &fdsCharL;
    case 'm':
      return &fdsCharm;
    case 'M':
      return &fdsCharM;
    case 'n':
      return &fdsCharn;
    case 'N':
      return &fdsCharN;
    case 'o':
      return &fdsCharo;
    case 'O':
      return &fdsCharO;
    case 'p':
      return &fdsCharp;
    case 'P':
      return &fdsCharP;
    case 'q':
      return &fdsCharq;
    case 'Q':
      return &fdsCharQ;
    case 'r':
      return &fdsCharr;
    case 'R':
      return &fdsCharR;
    case 's':
      return &fdsChars;
    case 'S':
      return &fdsCharS;
    case 't':
      return &fdsChart;
    case 'T':
      return &fdsCharT;
    case 'u':
      return &fdsCharu;
    case 'U':
      return &fdsCharU;
    case 'v':
      return &fdsCharv;
    case 'V':
      return &fdsCharV;
    case 'w':
      return &fdsCharw;
    case 'W':
      return &fdsCharW;
    case 'x':
      return &fdsCharx;
    case 'X':
      return &fdsCharX;
    case 'y':
      return &fdsChary;
    case 'Y':
      return &fdsCharY;
    case 'z':
      return &fdsCharz;
    case 'Z':
      return &fdsCharZ;
    case '0':
      return &fdsChar0;
    case '1':
      return &fdsChar1;
    case '2':
      return &fdsChar2;
    case '3':
      return &fdsChar3;
    case '4':
      return &fdsChar4;
    case '5':
      return &fdsChar5;
    case '6':
      return &fdsChar6;
    case '7':
      return &fdsChar7;
    case '8':
      return &fdsChar8;
    case '9':
      return &fdsChar9;
    case ':':
      return &fdsCharColon;
    case '-':
      return &fdsCharDash;
    case '\'':
      return &fdsCharSingleQuote;
    case ',':
      return &fdsCharComma;
    case '!':
      return &fdsCharBang;
    case ' ':
      return &fdsCharSpace;

    default:
      return &fdsCharUnknown;
  }
}
