-- phpMyAdmin SQL Dump
-- version 3.4.11.1deb1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Mar 12, 2013 at 01:53 PM
-- Server version: 5.5.28
-- PHP Version: 5.4.6-1ubuntu1.1

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `bakaplan`
--

-- --------------------------------------------------------

--
-- Table structure for table `ClassDetails`
--

CREATE TABLE IF NOT EXISTS `ClassDetails` (
  `SNo` int(100) NOT NULL AUTO_INCREMENT,
  `ProjectID` int(100) NOT NULL,
  `ClassName` varchar(50) NOT NULL,
  `SubjectName` varchar(100) NOT NULL,
  `SubjectCode` varchar(100) NOT NULL,
  UNIQUE KEY `SNo` (`SNo`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `ProjectName`
--

CREATE TABLE IF NOT EXISTS `ProjectName` (
  `ProjectID` int(255) NOT NULL AUTO_INCREMENT,
  `EmailID` varchar(50) NOT NULL,
  `ProjectName` varchar(30) NOT NULL,
  PRIMARY KEY (`ProjectID`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=1002 ;

--
-- Dumping data for table `ProjectName`
--

INSERT INTO `ProjectName` (`ProjectID`, `EmailID`, `ProjectName`) VALUES
(1001, 'mandy@gmail.com', 'Exam');

-- --------------------------------------------------------

--
-- Table structure for table `RoomDetail`
--

CREATE TABLE IF NOT EXISTS `RoomDetail` (
  `SNo` int(100) NOT NULL AUTO_INCREMENT,
  `ProjectID` int(100) NOT NULL,
  `CentreName` varchar(100) NOT NULL,
  `RoomNo` varchar(100) NOT NULL,
  `Rows` int(30) NOT NULL,
  `Columns` int(30) NOT NULL,
  UNIQUE KEY `SNo` (`SNo`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `Session`
--

CREATE TABLE IF NOT EXISTS `Session` (
  `SNo` int(25) NOT NULL AUTO_INCREMENT,
  `EmailID` varchar(150) NOT NULL,
  `SessionID` varchar(250) NOT NULL,
  PRIMARY KEY (`SNo`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=40 ;

--
-- Dumping data for table `Session`
--

INSERT INTO `Session` (`SNo`, `EmailID`, `SessionID`) VALUES
(9, 'mandeep@gmail.com', '4a27346e94ed9f8d9dc3c3d42cbfcd3fee9bf5b556828372c09399e766712873'),
(10, 'mandeep@gmail.com', '4a27346e94ed9f8d9dc3c3d42cbfcd3fffb51880e37fbac1c20289a86c250fe6'),
(11, 'mandeep@gmail.com', '4a27346e94ed9f8d9dc3c3d42cbfcd3fffb51880e37fbac1c20289a86c250fe6'),
(12, 'mandeep@gmail.com', '4a27346e94ed9f8d9dc3c3d42cbfcd3fffb51880e37fbac1c20289a86c250fe6'),
(13, 'mandeep@gmail.com', '4a27346e94ed9f8d9dc3c3d42cbfcd3fffb51880e37fbac1c20289a86c250fe6'),
(14, 'mandy@gmail.com', 'e785153308eca0740040a5c6e9cfe6d1ffb51880e37fbac1c20289a86c250fe6'),
(15, 'mandy@gmail.com', 'e785153308eca0740040a5c6e9cfe6d1ffb51880e37fbac1c20289a86c250fe6'),
(16, 'mandy@gmail.com', 'e785153308eca0740040a5c6e9cfe6d1ffb51880e37fbac1c20289a86c250fe6'),
(17, 'mandy@gmail.com', 'e785153308eca0740040a5c6e9cfe6d1ffb51880e37fbac1c20289a86c250fe6'),
(18, 'mandy@gmail.com', 'e785153308eca0740040a5c6e9cfe6d1ffb51880e37fbac1c20289a86c250fe6'),
(19, 'mandy@gmail.com', 'e785153308eca0740040a5c6e9cfe6d1ffb51880e37fbac1c20289a86c250fe6'),
(20, 'mandy@gmail.com', 'e785153308eca0740040a5c6e9cfe6d1ffb51880e37fbac1c20289a86c250fe6'),
(21, 'mandy@gmail.com', 'e785153308eca0740040a5c6e9cfe6d1ffb51880e37fbac1c20289a86c250fe6'),
(22, 'mandy@gmail.com', 'e785153308eca0740040a5c6e9cfe6d1ffb51880e37fbac1c20289a86c250fe6'),
(23, 'mandy@gmail.com', 'e785153308eca0740040a5c6e9cfe6d1ffb51880e37fbac1c20289a86c250fe6'),
(24, 'mandy@gmail.com', 'e785153308eca0740040a5c6e9cfe6d1ffb51880e37fbac1c20289a86c250fe6'),
(25, 'mandy@gmail.com', 'e785153308eca0740040a5c6e9cfe6d1ffb51880e37fbac1c20289a86c250fe6'),
(26, 'mandy@gmail.com', 'e785153308eca0740040a5c6e9cfe6d1ffb51880e37fbac1c20289a86c250fe6'),
(27, 'mandy@gmail.com', 'e785153308eca0740040a5c6e9cfe6d1ffb51880e37fbac1c20289a86c250fe6'),
(28, 'mandy@gmail.com', 'e785153308eca0740040a5c6e9cfe6d1ffb51880e37fbac1c20289a86c250fe6'),
(29, 'mandy@gmail.com', 'e785153308eca0740040a5c6e9cfe6d1bc900dbd983d731e9eaea7a59a4411f9'),
(30, 'mandy@gmail.com', 'e785153308eca0740040a5c6e9cfe6d1bc900dbd983d731e9eaea7a59a4411f9'),
(31, 'mandy@gmail.com', 'e785153308eca0740040a5c6e9cfe6d1bc900dbd983d731e9eaea7a59a4411f9'),
(32, 'mandy@gmail.com', 'e785153308eca0740040a5c6e9cfe6d1bc900dbd983d731e9eaea7a59a4411f9'),
(33, 'mandeep@gmail.com', '4a27346e94ed9f8d9dc3c3d42cbfcd3fbc900dbd983d731e9eaea7a59a4411f9'),
(34, 'mandeep@gmail.com', '4a27346e94ed9f8d9dc3c3d42cbfcd3fbc900dbd983d731e9eaea7a59a4411f9'),
(35, 'mandeep@gmail.com', '4a27346e94ed9f8d9dc3c3d42cbfcd3fbc900dbd983d731e9eaea7a59a4411f9'),
(36, 'mandeep@gmail.com', '4a27346e94ed9f8d9dc3c3d42cbfcd3fbc900dbd983d731e9eaea7a59a4411f9'),
(37, 'mandeep@gmail.com', '4a27346e94ed9f8d9dc3c3d42cbfcd3fbc900dbd983d731e9eaea7a59a4411f9'),
(38, 'mandeep@gmail.com', '4a27346e94ed9f8d9dc3c3d42cbfcd3fbc900dbd983d731e9eaea7a59a4411f9'),
(39, 'mandeep@gmail.com', '4a27346e94ed9f8d9dc3c3d42cbfcd3fbc900dbd983d731e9eaea7a59a4411f9');

-- --------------------------------------------------------

--
-- Table structure for table `Strategy`
--

CREATE TABLE IF NOT EXISTS `Strategy` (
  `SNo` int(100) NOT NULL AUTO_INCREMENT,
  `ProjectID` int(100) NOT NULL,
  `StrategyName` varchar(100) NOT NULL,
  PRIMARY KEY (`SNo`),
  UNIQUE KEY `SNo` (`SNo`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `TotalCentres`
--

CREATE TABLE IF NOT EXISTS `TotalCentres` (
  `SNo` int(100) NOT NULL AUTO_INCREMENT,
  `ProjectID` int(100) NOT NULL,
  `TotalCentres` int(50) NOT NULL,
  KEY `SNo` (`SNo`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `TotalClasses`
--

CREATE TABLE IF NOT EXISTS `TotalClasses` (
  `ProjectID` int(255) NOT NULL,
  `TotalClasses` int(30) NOT NULL,
  PRIMARY KEY (`ProjectID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `TotalRooms`
--

CREATE TABLE IF NOT EXISTS `TotalRooms` (
  `SNo` int(100) NOT NULL AUTO_INCREMENT,
  `ProjectID` int(100) NOT NULL,
  `CentreName` varchar(100) NOT NULL,
  `TotalRooms` int(70) NOT NULL,
  KEY `SNo` (`SNo`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `User`
--

CREATE TABLE IF NOT EXISTS `User` (
  `SNo` int(50) NOT NULL AUTO_INCREMENT,
  `EmailID` varchar(30) NOT NULL,
  `Password` varchar(250) NOT NULL,
  PRIMARY KEY (`EmailID`),
  KEY `SNo` (`SNo`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=10 ;

--
-- Dumping data for table `User`
--

INSERT INTO `User` (`SNo`, `EmailID`, `Password`) VALUES
(8, 'abc@123.com', 'e10adc3949ba59abbe56e057f20f883e'),
(7, 'mandeep@gmail.com', '202cb962ac59075b964b07152d234b70'),
(9, 'mandy@gmail.com', '81dc9bdb52d04dc20036dbd8313ed055');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
