# Freight-Forwader-Support-Software
Freight Forwarder Support Software is primarily an early-stage that trying to be ERP system completely free and open source. Also supports for all platforms. It's in early development stage right now. Currently only has below features.

- Freight Calculator
- Custom Calculator
- Container Tracking (Currently only has support for Cosco and MSC)
- Easy calculator (You can copy and paste any text into the textbox and it calculates every number inside it. Also you can use arithmetical operators using like 3*2 or 10/2).

***

## Getting Started
Visual Studio 2019 or 2022 is recommended, Forwarder Support Software is officially untested on other development environments whilst current now focus on a Windows build.

**1. Downloading the repository:**

Start by cloning the repository with `git clone --recursive https://github.com/TheMachineAmbassador/Freight-Forwader-Support-Software.git`.

If the repository was cloned non-recursively previously, use `git submodule update --init` to clone the necessary submodules.

**2. Configuring the dependencies:**

    1. Download the latest wxWidgets source from the https://www.wxwidgets.org/downloads/ and build the code. (You can found how to build using this site https://wiki.wxwidgets.org/Compiling_and_getting_started)
    2. Copy wxWidgets compiled "library" and "include" file on to 3rdparty/wxWidgets folder. 
    3. After copied you can start ForwarderSupportSoftware.sln and start working on the code

***

## The Plan
The plan for Freight Forwarder Support is currently integrating container tracking side for all carriers. Then making much more easy track loads. After then i want to make this program to work on all platforms and delivering software for all Logistic sector workers completely free and portable.

### Main features to come:
- Integrating container tracking for all carriers 
- Multiple mail sender
- Multiple container ETA tracker
- Much better freight calculating system and custom calculator