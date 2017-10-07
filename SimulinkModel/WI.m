function WI(block)
% Level-2 M file S-Function for interface demo.
%   Copyright 1990-2004 The MathWorks, Inc.
%   $Revision: 1.1.6.1 $ 

  setup(block);
end

%% Reset button and setup input/output port
function setup(block)
  global timebutton
  global timesetbutton
  global alarmbutton
  global plusbutton
  global minusbutton
  global swatchbutton
  
  % Register dialog parameters: No parameters for this block 
  block.NumDialogPrms = 0;
  
  % Register number of input and output ports
  block.NumInputPorts  = 9;

  % Setup functional port properties to dynamically inherited.
  block.SetPreCompInpPortInfoToDynamic; % port inherits sample rates

  % Primitive type
  % 8 for boolean, 0 for double, 3 for uint8 4 for int8
  
  % Input 1 is for hours
  block.InputPort(1).Complexity         = 'Real'; 
  block.InputPort(1).DataTypeId         = 3;                     
  block.InputPort(1).SamplingMode       = 'Sample';
  block.InputPort(1).Dimensions         = 1;
  block.InputPort(1).DirectFeedthrough  = 0;

  % Input 2 is for minutes
  block.InputPort(2).Complexity         = 'Real'; 
  block.InputPort(2).DataTypeId         = 3;                     
  block.InputPort(2).SamplingMode       = 'Sample';
  block.InputPort(2).Dimensions         = 1;
  block.InputPort(2).DirectFeedthrough  = 0;

  % Input 3 is for seconds
  block.InputPort(3).Complexity         = 'Real'; 
  block.InputPort(3).DataTypeId         = 3;                     
  block.InputPort(3).SamplingMode       = 'Sample';
  block.InputPort(3).Dimensions         = 1;
  block.InputPort(3).DirectFeedthrough  = 0;

  % Input 4 is for tenths
  block.InputPort(4).Complexity         = 'Real'; 
  block.InputPort(4).DataTypeId         = 3;                     
  block.InputPort(4).SamplingMode       = 'Sample';
  block.InputPort(4).Dimensions         = 1;
  block.InputPort(4).DirectFeedthrough  = 0;

  % Input 5 is for mode
  block.InputPort(5).Complexity         = 'Real'; 
  block.InputPort(5).DataTypeId         = 3;                     
  block.InputPort(5).SamplingMode       = 'Sample';
  block.InputPort(5).Dimensions         = 1;
  block.InputPort(5).DirectFeedthrough  = 0;
  
  % Input 6 is for activealarm
  block.InputPort(6).Complexity         = 'Real'; 
  block.InputPort(6).DataTypeId         = 8;
  block.InputPort(6).SamplingMode       = 'Sample';
  block.InputPort(6).Dimensions         = 1;
  block.InputPort(6).DirectFeedthrough  = 0;
  
  % Input 7 is for hblink
  block.InputPort(7).Complexity         = 'Real'; 
  block.InputPort(7).DataTypeId         = 8;
  block.InputPort(7).SamplingMode       = 'Sample';
  block.InputPort(7).Dimensions         = 1;
  block.InputPort(7).DirectFeedthrough  = 0;
  
  % Input 8 is for mblink
  block.InputPort(8).Complexity         = 'Real'; 
  block.InputPort(8).DataTypeId         = 8;
  block.InputPort(8).SamplingMode       = 'Sample';
  block.InputPort(8).Dimensions         = 1;
  block.InputPort(8).DirectFeedthrough  = 0;
  
  % Input 9 is for ringalarm
  block.InputPort(9).Complexity         = 'Real'; 
  block.InputPort(9).DataTypeId         = 8;
  block.InputPort(9).SamplingMode       = 'Sample';
  block.InputPort(9).Dimensions         = 1;
  block.InputPort(9).DirectFeedthrough  = 0;
  
  block.NumOutputPorts = 6;

  % Setup functional port properties to dynamically inherited.
  block.SetPreCompOutPortInfoToDynamic;
  
  % Primitive type
  % 8 for boolean, 0 for double, 3 for uint8 4 for int8

  block.OutputPort(1).Complexity   = 'Real'; 
  block.OutputPort(1).DataTypeId   = 8;
  block.OutputPort(1).SamplingMode = 'Sample';
  block.OutputPort(1).Dimensions   = 1;

  block.OutputPort(2).Complexity   = 'Real'; 
  block.OutputPort(2).DataTypeId   = 8;
  block.OutputPort(2).SamplingMode = 'Sample';
  block.OutputPort(2).Dimensions   = 1;

  block.OutputPort(3).Complexity   = 'Real'; 
  block.OutputPort(3).DataTypeId   = 8;
  block.OutputPort(3).SamplingMode = 'Sample';
  block.OutputPort(3).Dimensions   = 1;

  block.OutputPort(4).Complexity   = 'Real'; 
  block.OutputPort(4).DataTypeId   = 8;
  block.OutputPort(4).SamplingMode = 'Sample';
  block.OutputPort(4).Dimensions   = 1;

  block.OutputPort(5).Complexity   = 'Real'; 
  block.OutputPort(5).DataTypeId   = 8;
  block.OutputPort(5).SamplingMode = 'Sample';
  block.OutputPort(5).Dimensions   = 1;

  block.OutputPort(6).Complexity   = 'Real'; 
  block.OutputPort(6).DataTypeId   = 8;
  block.OutputPort(6).SamplingMode = 'Sample';
  block.OutputPort(6).Dimensions   = 1;

  % Register methods
  block.RegBlockMethod('SetInputPortSamplingMode', @SetInputPortSamplingMode);
  block.RegBlockMethod('Start',                    @Start);  
  block.RegBlockMethod('Outputs',                  @Outputs);

  timebutton = 0;
  timesetbutton = 0;
  alarmbutton = 0;
  plusbutton = 0;
  minusbutton = 0;
  swatchbutton = 0;
 
end

%% Set input port correct sampling time
function SetInputPortSamplingMode(block, idx, fd)
   block.InputPort(idx).SamplingMode = fd;
end

%% Check if one or more button are pressed
function ButtonDown(hObj, evnt)
   global timebutton
   global timesetbutton
   global alarmbutton
   global plusbutton
   global minusbutton
   global swatchbutton 

  pos = get(hObj,'CurrentPoint');

  if ((pos(2) > 240-(188+41)) && (pos(2) < 240-188) && (pos(1) > 25) && (pos(1) < (25+44)))
            timebutton=1;
  end
  if ((pos(2) > 240-(188+41)) && (pos(2) < 240-188) && (pos(1) > 95) && (pos(1) < (95+42)))
            timesetbutton=1;
  end
  if ((pos(2) > 240-(188+43)) && (pos(2) < 240-188) && (pos(1) > 165) && (pos(1) < (165+42)))
            alarmbutton=1;
  end
  if ((pos(2) > 240-(28+36)) && (pos(2) < 240-28) && (pos(1) > 256) && (pos(1) < (256+36)))
            plusbutton=1;
  end
  if ((pos(2) > 240-(100+34)) && (pos(2) < 240-100) && (pos(1) > 255) && (pos(1) < (255+38)))
            minusbutton=1;
  end
  if ((pos(2) > 240-(187+41)) && (pos(2) < 240-187) && (pos(1) > 242) && (pos(1) < (242+38)))
            swatchbutton=1;
  end
end

%% Check if one or more button are released
function ButtonUp(hObj, evnt)
   global timebutton
   global timesetbutton
   global alarmbutton
   global plusbutton
   global minusbutton
   global swatchbutton
 
  pos = get(hObj,'CurrentPoint');

  if ((pos(2) > 240-(188+41)) && (pos(2) < 240-188) && (pos(1) > 25) && (pos(1) < (25+44)))
            timebutton=0;
  end
  if ((pos(2) > 240-(188+41)) && (pos(2) < 240-188) && (pos(1) > 95) && (pos(1) < (95+42)))
            timesetbutton=0;
  end
  if ((pos(2) > 240-(188+43)) && (pos(2) < 240-188) && (pos(1) > 165) && (pos(1) < (165+42)))
            alarmbutton=0;
  end
  if ((pos(2) > 240-(28+36)) && (pos(2) < 240-28) && (pos(1) > 256) && (pos(1) < (256+36)))
            plusbutton=0;
  end
  if ((pos(2) > 240-(100+34)) && (pos(2) < 240-100) && (pos(1) > 255) && (pos(1) < (255+38)))
            minusbutton=0;
  end
  if ((pos(2) > 240-(187+41)) && (pos(2) < 240-187) && (pos(1) > 242) && (pos(1) < (242+38)))
            swatchbutton=0;
  end
end

%% Setup the graphics settings of the block
function Start(block) 

  global IM
  global FH
  global timemode_hnd;
  global timesetmode_hnd;
  global alarmsetmode_hnd;
  global swatchmode_hnd;
  global activealarmon_hnd;
  global activealarmoff_hnd;
  
  global hrs_digits;
  global min_digits;
  global sec_digits;
  global ten_digits;
 
  global timemode;
  global timesetmode;
  global alarmsetmode;
  global swatchmode;
  global activealarmon;
  global activealarmoff;
  
  global sep2;
  global sep3;

  IM = imread('images/background.png');
  timemode = imread('images/timeON.png');
  timesetmode = imread('images/timesetON.png');
  alarmsetmode = imread('images/alarmnactiveON.png');
  swatchmode = imread('images/swatchON.png');
  activealarmon = imread('images/alarmactiveON.png');
  activealarmoff = imread('images/alarmactiveOFF.png');

  
  bhD = @ButtonDown;
  bhU = @ButtonUp;

  % background image 

  FH = figure('Toolbar', 'none', 'Menubar', 'none', 'Name', 'Figname', 'WindowButtonDownFcn', bhD, 'WindowButtonUpFcn', bhU, 'Resize', 'off');
  scrsz = get(0,'ScreenSize');
  set(FH, 'Units','pixels');
  set(FH, 'Position',[1 scrsz(4)-500 320 240]);
  axes('Units', 'pixels', 'Position', [1, 1, 320, 240], 'Visible', 'off');
  image(IM)
  axis off

  % text output
   
  hrs_digits = text(33, 240-68,'', 'Units', 'pixels', 'FontUnits', 'points', 'FontSize', 32);
  set(hrs_digits, 'Color',[1 1 1]);
  set(hrs_digits, 'VerticalAlignment','top');
  set(hrs_digits, 'FontName', 'Arial');

  sep1 = text(78, 240-68,'', 'Units', 'pixels', 'FontUnits', 'points', 'FontSize', 32);
  set(sep1, 'Color',[1 1 1]);
  set(sep1, 'VerticalAlignment','top');
  set(sep1, 'FontName', 'Arial');
  set(sep1, 'string', ':');

  min_digits = text(89, 240-68,'', 'Units', 'pixels', 'FontUnits', 'points', 'FontSize', 32);
  set(min_digits, 'Color',[1 1 1]);
  set(min_digits, 'VerticalAlignment','top');
  set(min_digits, 'FontName', 'Arial');

  sep2 = text(134, 240-68,'', 'Units', 'pixels', 'FontUnits', 'points', 'FontSize', 32);
  set(sep2, 'Color',[1 1 1]);
  set(sep2, 'VerticalAlignment','top');
  set(sep2, 'FontName', 'Arial');
  set(sep2, 'string', ':');

  sec_digits = text(145, 240-68,'', 'Units', 'pixels', 'FontUnits', 'points', 'FontSize', 32);
  set(sec_digits, 'Color',[1 1 1]);
  set(sec_digits, 'VerticalAlignment','top');
  set(sec_digits, 'FontName', 'Arial');

  sep3 = text(188, 240-68,'', 'Units', 'pixels', 'FontUnits', 'points', 'FontSize', 32);
  set(sep3, 'Color',[1 1 1]);
  set(sep3, 'VerticalAlignment','top');
  set(sep3, 'FontName', 'Arial');
  set(sep3, 'string', '.');

  ten_digits = text(199, 240-68,'', 'Units', 'pixels', 'FontUnits', 'points', 'FontSize', 32);
  set(ten_digits, 'Color',[1 1 1]);
  set(ten_digits, 'VerticalAlignment','top');
  set(ten_digits, 'FontName', 'Arial');

  axes('Units', 'pixels', 'Position', [30, 10, 40, 40], 'Visible', 'off');
  timemode_hnd = image(timemode, 'Visible', 'off');
  axis off;
  axes('Units', 'pixels', 'Position', [100, 10, 40, 40], 'Visible', 'off');
  timesetmode_hnd = image(timesetmode, 'Visible', 'off');
  axis off;
  axes('Units', 'pixels', 'Position', [170, 10, 40, 40], 'Visible', 'off');
  alarmsetmode_hnd = image(alarmsetmode, 'Visible', 'off');
  axis off;
  axes('Units', 'pixels', 'Position', [240, 10, 40, 40], 'Visible', 'off');
  swatchmode_hnd = image(swatchmode, 'Visible', 'off');
  axis off;
  axes('Units', 'pixels', 'Position', [170, 10, 40, 40], 'Visible', 'off');
  activealarmon_hnd = image(activealarmon, 'Visible', 'off');
  axis off;
  axes('Units', 'pixels', 'Position', [170, 10, 40, 40], 'Visible', 'off');
  activealarmoff_hnd = image(activealarmoff, 'Visible', 'off');
  axis off;
end

%% Convert an integer to 2-digits string
function con_str = convertDto2S(dig)
  shw_val = mod(dig, 100);
  con_str = int2str(shw_val);
  if shw_val < 10 
      con_str = strcat('0',con_str);
  end
end

%% Convert an integer to 1-digit string
function con_str = convertDto1S(dig)
  shw_val = mod(dig, 10);
  con_str = int2str(shw_val);
end

%% Let the system update the output port
function Outputs(block)
  
   global timebutton
   global timesetbutton
   global alarmbutton
   global plusbutton
   global minusbutton
   global swatchbutton
   
   global timemode_hnd;
   global timesetmode_hnd;
   global alarmsetmode_hnd;
   global swatchmode_hnd;
   global activealarmon_hnd;
   global activealarmoff_hnd;

   global hrs_digits;
   global min_digits;
   global sec_digits;
   global ten_digits;
 
   global sep2;
   global sep3;

%Update graphics based on input ports

% Need to transform block.InputPort(1).Data value into string of 2 chars
  set(hrs_digits, 'string',  convertDto2S(block.InputPort(1).Data))

% Hour blinking
  if(block.InputPort(7).Data == 1)
      set(hrs_digits, 'Visible', 'off')
  else
      set(hrs_digits, 'Visible', 'on')
  end
 
% Need to transform block.InputPort(2).Data value into string of 2 chars
  set(min_digits, 'string', convertDto2S(block.InputPort(2).Data))
  
  % Minute blinking
  if(block.InputPort(8).Data == 1)
      set(min_digits, 'Visible', 'off')
  else
      set(min_digits, 'Visible', 'on')
  end
  
% Need to transform block.InputPort(3).Data value into string of 2 chars
% display is on only if mode is time or stopwatch
  if (block.InputPort(5).Data == 3) || (block.InputPort(5).Data == 0) 
    set(sec_digits, 'Visible', 'on')
    set(sec_digits, 'string', convertDto2S(block.InputPort(3).Data))
    set(sep2, 'Visible', 'on')
  else
    set(sec_digits, 'Visible', 'off')
    set(sep2, 'Visible', 'off')
  end
  
% Need to transform block.InputPort(4).Data value into string of 1 char
% display is on only if mode is stopwatch
  if block.InputPort(5).Data == 3  
    set(ten_digits, 'Visible', 'on')
    set(ten_digits, 'string', convertDto1S(block.InputPort(4).Data))
    set(sep3, 'Visible', 'on')
  else
    set(ten_digits, 'Visible', 'off')
    set(sep3, 'Visible', 'off')
  end
  
  if block.InputPort(5).Data == 0 
      set(timemode_hnd, 'Visible', 'on')
  else
      set(timemode_hnd, 'Visible', 'off')
  end

  if block.InputPort(5).Data == 1 
      set(timesetmode_hnd, 'Visible', 'on')
  else
      set(timesetmode_hnd, 'Visible', 'off')
  end

  if block.InputPort(5).Data == 2 && block.InputPort(6).Data == 0
      set(activealarmon_hnd, 'Visible', 'off')
      set(activealarmoff_hnd, 'Visible', 'off') 
      set(alarmsetmode_hnd, 'Visible', 'on')
  elseif block.InputPort(5).Data == 2 && block.InputPort(6).Data == 1
      set(activealarmon_hnd, 'Visible', 'on')
      set(activealarmoff_hnd, 'Visible', 'off')
      set(alarmsetmode_hnd, 'Visible', 'off')
  elseif block.InputPort(5).Data ~= 2 && block.InputPort(6).Data == 1
      set(activealarmon_hnd, 'Visible', 'off')
      if(block.InputPort(9).Data == 1)
        set(activealarmoff_hnd, 'Visible', 'off')
      else
        set(activealarmoff_hnd, 'Visible', 'on') 
      end
      set(alarmsetmode_hnd, 'Visible', 'off')
  else
      set(activealarmon_hnd, 'Visible', 'off')
      set(activealarmoff_hnd, 'Visible', 'off')
      set(alarmsetmode_hnd, 'Visible', 'off')
  end

  if block.InputPort(5).Data == 3 
      set(swatchmode_hnd, 'Visible', 'on')
  else
      set(swatchmode_hnd, 'Visible', 'off')
  end
  
% Update output ports

  block.OutputPort(1).Data = boolean(plusbutton);   
  block.OutputPort(2).Data = boolean(minusbutton);   
  block.OutputPort(3).Data = boolean(timebutton);   
  block.OutputPort(4).Data = boolean(timesetbutton);   
  block.OutputPort(5).Data = boolean(alarmbutton);   
  block.OutputPort(6).Data = boolean(swatchbutton);
end

