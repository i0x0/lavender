/**
 *  @file    main.cpp
 *  @author  i0x0
 *  @date    2024-06-30
 *  @version 0.0.1
 *
 *  This is the main file for cpp_test.
 *  Original example file by WerWolv.
 */

#include <switch.h> //The nxlib header file. It includes the functions which allow you to talk to the switch software/hardware
#include <stdio.h>  //Used for printf
#include <borealis.hpp>
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/errno.h>
#include <unistd.h>
#include <TrustWalletCore/TWCoinType.h>
#include <TrustWalletCore/TWAnySigner.h>
#include <TrustWalletCore/TWCoinTypeConfiguration.h>
#include <TrustWalletCore/TWHDWallet.h>
#include <TrustWalletCore/TWPrivateKey.h>
#include <TrustWalletCore/TWString.h>

using namespace std;
namespace i18n = brls::i18n;    // for loadTranslations() and getStr()
using namespace i18n::literals; // for _i18n

void print_debug(std::string str)
{
  str = "[DETAILS] " + str + "\n";
  printf(str.c_str());
}

int main(int argc, char **argv)
{
  brls::Logger::setLogLevel(brls::LogLevel::DEBUG);

  brls::i18n::loadTranslations();
  if (!brls::Application::init("main/name"_i18n))
  {
    brls::Logger::error("Unable to init Borealis application");
    return EXIT_FAILURE;
  }

  brls::StagedAppletFrame *rootFrame = new brls::StagedAppletFrame();

  rootFrame->setTitle("main/name"_i18n);
  rootFrame->setIcon(BOREALIS_ASSET("icon/lavender.jpg"));

  TWHDWallet *walletNew = TWHDWalletCreate(128, TWStringCreateWithUTF8Bytes(""));
  brls::Label *testLabel = new brls::Label(brls::LabelStyle::REGULAR, "main/more"_i18n, true);
  testLabel->setText(TWStringUTF8Bytes(TWHDWalletMnemonic(walletNew)));

  brls::Application::pushView(rootFrame);
  while (brls::Application::mainLoop())
    ;

  print_debug("Main loop end.");
  return EXIT_SUCCESS;
}
