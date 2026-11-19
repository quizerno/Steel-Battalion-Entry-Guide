# 5A. Pedal Adapters


## Multifunction Adapters

A catch all option. Various AliExpress sellers carry a [Simracing Game Pedal Gear Shift-er MOD Adapter Converter For Logitech G25/G27/G29 For Thrustmaster T3PA PRO Pedal"](https://www.aliexpress.us/item/3256812791035767.html?spm=a2g0o.productlist.main.1.20b87de1Hi7Gnp&algo_pvid=7b7f645d-d0ea-45f3-bc56-337b29560490&algo_exp_id=7b7f645d-d0ea-45f3-bc56-337b29560490-0&pdp_ext_f=%7B%22order%22%3A%22-1%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21USD%2173.30%2124.19%21%21%21486.07%21160.41%21%402101c68a17950962863083912e0c77%2112000059928068679%21sea%21US%210%21ABX%211%210%21n_tag%3A-29910%3Bd%3A65965e63%3Bm03_new_user%3A-29895&curPageLogUid=xsIYzWt58ueH&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005012977350519%7C_p_origin_prod%3A)

## Hall-Effect Adapters (Thrustmaster and GoKart Pedals)

Harcroft's Hall-Effect Adapter is used to convert the logarithmic signals to linear, for use with the original controller
His circuit works with Thrustmaster pedals and GoKart pedals sold on Aliexpress. Harcroft sells both versions of this adaoter.

For playing on PC. Thrustmaster sells a USB adapter (([T.RJ12 USB Adapter](https://www.amazon.com/Thrustmaster-J12-Adapter-Pedals-multi-USB-calibration/dp/B01F41W63S/ref=sr_1_5?channelId=500&clpRedir=Y&dib=eyJ2IjoiMSJ9.S_fUwRCGVUzF8QqwS8eacFp_S2x9LX8R18wX-xrnonuObh2QKgxfnj0GbAQEV2QahhkRSVeU6OXqOwT_qinRvRcUBVrPTvsyl0d2wEQd0VQHcZ5s_jgKAnmTFjDJPSNcXBxmYbyVxM0Fg9mKB-dea-Tt3rCOtOkQB3cBl3HccwiOYraauG_dbnRhz6hBIOV7JNfZrfQnFYOkP5_grq7jkb96ub_pIE8n__y0WVy5DvU.oAN50bsBr2S4G3SW5lqsJK3fidM9_hUNc-PLgzzrloc&dib_tag=se&keywords=logitech+pedal+adapter&plpRedirect=mhFallback&qid=1794432656&sr=8-5))
 which eliminates need of the converter circuit.


If you would like to make it yourself

Components:
* 1 x MCP6004-I/P-ND OP-AMP
* 6 x 1N4934 Diodes
* 1 x 1uf Capacitor
* 3 x 10K potentiometers
* 3 x 100 kΩ Resistors
* Solderable breadboard

Input:
* **If adapting the Thrustmaster pedals:** you will need a female RJ-12 cable and follow the wiring.
* **If adapting the dapt the GoKart pedals:** you can wire directly to the circuit

Output:
* **If being used for the original controller:** you will need the Male Mini 6DIN connector
* **If being used for PC:** A microcontroller will be needed to convert the signals to USB.
**Thrustmaster Wiring**

<img width="328" height="294" alt="image" src="https://github.com/user-attachments/assets/3acff55c-bbcd-4924-91f4-a9bd55c9db70" />





<img width="508" height="667" alt="image" src="https://github.com/user-attachments/assets/8991af89-3c8f-4c01-9d85-3458ef5bea11" />



<img width="529" height="670" alt="image" src="https://github.com/user-attachments/assets/b478fba5-1957-4354-808a-abe5be4dbe54" />
<img width="817" height="600" alt="image" src="https://github.com/user-attachments/assets/1db602e6-73d5-40c9-9a50-2079d8c5e6b5" />


## Logitech Adapters

**For the Originsl Steel Battalion Controller**</br>

The Logitech Adapter designed and sold by Harcroft is a simple direct wiring adapoter.

* Mini-Din 6 male connector
* DE9 female connector

<img width="302.5" height="254.5" alt="image" src="https://github.com/user-attachments/assets/b740d8c6-5328-447d-a2ae-1e075b457dff" />


**For PC**</br>
For PC, there are many options

For purchase:
* [Leobodnar Adapter](https://www.leobodnar.com/shop/index.php?main_page=product_info&products_id=187)
* [Logitech's own Racing Adapter](https://www.logitechg.com/en-us/shop/p/racing-adapter.943-000435)
* [3DRap Adapter](https://3drap.com/products/usb-pedals-adapter-logitech-pc)
* 

DIY:
* [DIY Arduino Leonardo Tutorial by Dave Madison](https://www.partsnotincluded.com/how-to-build-a-diy-logitech-pedals-usb-adapter/), [Video](https://www.youtube.com/watch?v=6Pu1qknGjy4)
* [Similar Tutorial by amstudio](https://www.youtube.com/watch?v=k5CtXG1rpZg)
* [Similar Tutorial by GustavoGames](https://www.youtube.com/watch?v=y1NedF7eSfU) (uses AI dubbing)
